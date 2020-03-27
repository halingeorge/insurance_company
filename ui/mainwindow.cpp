#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QApplication>

#include <server/base.h>
#include <server/options.h>

#include <iostream>
#include <unistd.h>

namespace {

void FillWithDefualtValues(Ui::MainWindow* ui) {
  auto set_default = [](QTextEdit* input, std::string_view value) {
    input->setTextColor(QColorConstants::Black);
    input->setReadOnly(false);
    input->setText(value.data());
  };

  set_default(ui->fund_input, "30000");
  set_default(ui->tax_input, "2");
  set_default(ui->refund_input, "2");
  set_default(ui->customer_input, "100");
  set_default(ui->game_month_input, "24");

  set_default(ui->house_cost_input, "2000");
  set_default(ui->house_duration_input, "6");
  set_default(ui->house_min_input, "200");
  set_default(ui->house_max_input, "5000");
  set_default(ui->house_payment_frequency_input, "6");

  set_default(ui->car_cost_input, "500");
  set_default(ui->car_duration_input, "2");
  set_default(ui->car_min_input, "500");
  set_default(ui->car_max_input, "2000");
  set_default(ui->car_payment_frequency_input, "2");

  set_default(ui->health_cost_input, "200");
  set_default(ui->health_duration_input, "3");
  set_default(ui->health_min_input, "1000");
  set_default(ui->health_max_input, "3000");
  set_default(ui->health_payment_frequency_input, "3");
}

}  // namespace

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  insurance_inputs_ = {
      ui->house_cost_input,
      ui->house_duration_input,
      ui->house_min_input,
      ui->house_max_input,
      ui->house_payment_frequency_input,

      ui->car_cost_input,
      ui->car_duration_input,
      ui->car_min_input,
      ui->car_max_input,
      ui->car_payment_frequency_input,

      ui->health_cost_input,
      ui->health_duration_input,
      ui->health_min_input,
      ui->health_max_input,
      ui->health_payment_frequency_input
  };

  std::for_each(insurance_inputs_.begin(), insurance_inputs_.end(), [](QTextEdit* input) {
    input->setReadOnly(true);
  });

  FillWithDefualtValues(ui);
}

MainWindow::~MainWindow() {
  delete ui;
}

void Show(const std::string& error) {
  QMessageBox msgBox;
  msgBox.setText(QString::fromStdString(error));
  msgBox.exec();
}

void MainWindow::on_start_game_clicked() {
  auto optionsOrError = GameOptions::Init(
      ui->fund_input->toPlainText().toStdString(),
      ui->tax_input->toPlainText().toStdString(),
      ui->refund_input->toPlainText().toStdString(),
      ui->customer_input->toPlainText().toStdString(),
      ui->game_month_input->toPlainText().toStdString()
  );
  if (optionsOrError) {
    Show(optionsOrError.GetError());
    return;
  }

  game_.Init(optionsOrError.ValueOrThrow());

  on_update_insurances();
}

bool MainWindow::on_play_month_clicked() {
  if (!on_update_insurances()) {
    return false;
  }

  std::for_each(insurance_inputs_.begin(), insurance_inputs_.end(), [&](QTextEdit* input) {
    input->setReadOnly(true);
    input->setTextColor(QColorConstants::DarkRed);
    input->setText(input->toPlainText());
  });

  game_.PlayOneMonth();

  auto double_to_string = [&](double value) {
    auto str = std::to_string(static_cast<int>(value * 100) / 100.0);
    DEBUG("double_to_string: " << str);
    return str.substr(0, str.size() - 4);
  };

  DEBUG("size: " << game_.GetCompany().GetSoldInsurances().size());
  for (auto [key, value] : game_.GetCompany().GetSoldInsurances()) {
    DEBUG("key: " << static_cast<int>(key));
    DEBUG("value: " << value);
  }

  ui->house_sold_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetSoldInsurances().at(
      Insurance::Type::House))));
  ui->car_sold_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetSoldInsurances().at(
      Insurance::Type::Car))));
  ui->health_sold_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetSoldInsurances().at(
      Insurance::Type::Health))));

  DEBUG("size: " << game_.GetCompany().GetInsuranceCasesByType().size());
  ui->house_incidents_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetInsuranceCasesByType().at(
      Insurance::Type::House))));
  ui->car_incidents_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetInsuranceCasesByType().at(
      Insurance::Type::Car))));
  ui->health_incidents_output->setText(QString::fromStdString(std::to_string(game_.GetCompany().GetInsuranceCasesByType().at(
      Insurance::Type::Health))));

  DEBUG("size: " << game_.GetCompany().GetProfitByInsurance().size());
  ui->house_income_output->setText(QString::fromStdString(double_to_string(game_.GetCompany().GetProfitByInsurance().at(
      Insurance::Type::House))));
  ui->car_income_output->setText(QString::fromStdString(double_to_string(game_.GetCompany().GetProfitByInsurance().at(
      Insurance::Type::Car))));
  ui->health_income_output->setText(QString::fromStdString(double_to_string(game_.GetCompany().GetProfitByInsurance().at(
      Insurance::Type::Health))));

  ui->current_fund_output->setText(QString::fromStdString(double_to_string(game_.GetCompany().GetMoney())));
  ui->current_month_output->setText(QString::fromStdString(std::to_string(game_.GetPlayedMonth())));

  if (game_.HasCompanyLost()) {
    Show("Game over");
    on_freeze();
    return false;
  }

  if (game_.HasGameFinished()) {
    Show("You won!");
    on_freeze();
    return false;
  }

  CHECK(on_update_insurances());

  return true;
}

void MainWindow::on_play_until_end_clicked() {
  DEBUG("on_play_until_end");
  while (on_play_month_clicked()) {
    DEBUG("on_play_until_end");
  }
}

bool MainWindow::on_update_insurances() {
  if (!indexes_to_update_.empty()) {
    std::vector<Insurance> insurances;
    for (auto i : indexes_to_update_) {
      auto insuranceOrError = Insurance::Init(
          static_cast<Insurance::Type>(i / Insurance::ParameterCount),
          insurance_inputs_[i]->toPlainText().toStdString(),
          insurance_inputs_[i + 1]->toPlainText().toStdString(),
          insurance_inputs_[i + 2]->toPlainText().toStdString(),
          insurance_inputs_[i + 3]->toPlainText().toStdString(),
          insurance_inputs_[i + 4]->toPlainText().toStdString()
      );
      if (insuranceOrError) {
        Show(insuranceOrError.GetError());
        return false;
      }
      insurances.push_back(insuranceOrError.ValueOrThrow());
    }

    indexes_to_update_.clear();

    game_.GetCompany().UpdateInsurances(std::move(insurances));

    return true;
  }

  auto expired_insurance_types = game_.GetCompany().GetOutdatedInsurances();
  std::vector<QTextEdit*> related_insurances;
  for (size_t i = 0; i < insurance_inputs_.size(); i++) {
    size_t index = std::numeric_limits<size_t>::max();
    for (auto type : expired_insurance_types) {
      auto type_index = static_cast<size_t>(type);
      if (type_index * Insurance::ParameterCount <= i && i < (type_index + 1) * Insurance::ParameterCount) {
        if (i % Insurance::ParameterCount == 0) {
          index = i;
        }
        related_insurances.push_back(insurance_inputs_[i]);
      }
    }
    if (index != std::numeric_limits<size_t>::max()) {
      indexes_to_update_.push_back(index);
    }
  }

  std::for_each(related_insurances.begin(), related_insurances.end(), [&](QTextEdit* input) {
    input->setReadOnly(false);
    input->setTextColor(QColorConstants::DarkGreen);
    input->setText(input->toPlainText());
  });

  return true;
}

void MainWindow::on_freeze() {
  auto freeze = [](auto* input) {
    input->setReadOnly(true);
    input->setTextColor(QColorConstants::DarkRed);
    input->setText(input->toPlainText());
  };
  std::for_each(insurance_inputs_.begin(), insurance_inputs_.end(), [&](QTextEdit* input) {
    freeze(input);
  });

  freeze(ui->house_sold_output);
  freeze(ui->car_sold_output);
  freeze(ui->health_sold_output);

  freeze(ui->house_incidents_output);
  freeze(ui->car_incidents_output);
  freeze(ui->health_incidents_output);

  freeze(ui->house_income_output);
  freeze(ui->car_income_output);
  freeze(ui->health_income_output);

  freeze(ui->current_fund_output);
  freeze(ui->current_month_output);
}

int run_main_window(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
