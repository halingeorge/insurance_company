#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

#include "base.h"
#include "options.h"

#include <iostream>

namespace {

void FillWithDefualtValues(Ui::MainWindow* ui) {
    ui->fund_input->setText("30000");
    ui->tax_input->setText("9");
    ui->refund_input->setText("10");
    ui->customer_input->setText("25");

    ui->house_cost_input->setReadOnly(true);
    ui->house_cost_input->setText("200");
    ui->house_duration_input->setText("6");
    ui->house_min_input->setText("1000");
    ui->house_max_input->setText("20000");

    ui->car_cost_input->setText("50");
    ui->car_duration_input->setText("2");
    ui->car_min_input->setText("100");
    ui->car_max_input->setText("5000");

    ui->health_cost_input->setText("100");
    ui->health_duration_input->setText("3");
    ui->health_min_input->setText("300");
    ui->health_max_input->setText("10000");
}

}  // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FillWithDefualtValues(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Show(const std::string& error) {
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(error));
    msgBox.exec();
}

void MainWindow::on_start_game_clicked()
{
    auto optionsOrError = GameOptions::Init(
        ui->fund_input->toPlainText().toStdString(),
        ui->tax_input->toPlainText().toStdString(),
        ui->refund_input->toPlainText().toStdString(),
        ui->customer_input->toPlainText().toStdString()
    );
    if (optionsOrError) {
        Show(optionsOrError.GetError());
        return;
    }
    game_.SetOptions(optionsOrError.ValueOrThrow());
}
