#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <server/game.h>

#include <QMainWindow>
#include <QTextEdit>

#include <unordered_map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_start_game_clicked();
  bool on_play_month_clicked();
  void on_play_until_end_clicked();

 private:
  bool on_update_insurances();
  void on_freeze();

 private:
  Ui::MainWindow* ui;
  Game game_;
  std::vector<QTextEdit*> insurance_inputs_;
  std::vector<size_t> indexes_to_update_;
};

int run_main_window(int argc, char* argv[]);

#endif // MAINWINDOW_H
