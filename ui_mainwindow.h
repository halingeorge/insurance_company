/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *play_month;
    QPushButton *start_game;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *house_cost_input;
    QTextEdit *house_duration_input;
    QTextEdit *house_min_input;
    QTextEdit *house_max_input;
    QLabel *label_10;
    QLabel *label_11;
    QTextEdit *customer_input;
    QLabel *label_12;
    QLabel *label_13;
    QTextEdit *fund_input;
    QLabel *label_14;
    QTextEdit *refund_input;
    QLabel *label_15;
    QLabel *label_16;
    QTextEdit *car_max_input;
    QTextEdit *car_min_input;
    QTextEdit *car_cost_input;
    QTextEdit *car_duration_input;
    QTextEdit *health_max_input;
    QTextEdit *health_cost_input;
    QTextEdit *health_duration_input;
    QTextEdit *health_min_input;
    QPushButton *update_house;
    QPushButton *update_car;
    QPushButton *update_health;
    QTextBrowser *house_sold_output;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_23;
    QTextBrowser *house_refund_output;
    QTextBrowser *house_income_output;
    QTextBrowser *car_income_output;
    QTextBrowser *car_refund_output;
    QTextBrowser *car_sold_output;
    QTextBrowser *health_income_output;
    QTextBrowser *health_refund_output;
    QTextBrowser *health_sold_output;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QTextBrowser *current_fund_output;
    QLabel *label_6;
    QLabel *label_21;
    QTextEdit *tax_input;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        play_month = new QPushButton(centralwidget);
        play_month->setObjectName(QString::fromUtf8("play_month"));
        play_month->setGeometry(QRect(570, 420, 141, 41));
        start_game = new QPushButton(centralwidget);
        start_game->setObjectName(QString::fromUtf8("start_game"));
        start_game->setGeometry(QRect(630, 40, 141, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 140, 91, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 130, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 140, 91, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 140, 91, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(320, 140, 91, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 170, 61, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 200, 91, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 230, 91, 16));
        house_cost_input = new QTextEdit(centralwidget);
        house_cost_input->setObjectName(QString::fromUtf8("house_cost_input"));
        house_cost_input->setGeometry(QRect(120, 170, 91, 21));
        house_duration_input = new QTextEdit(centralwidget);
        house_duration_input->setObjectName(QString::fromUtf8("house_duration_input"));
        house_duration_input->setGeometry(QRect(220, 170, 91, 21));
        house_min_input = new QTextEdit(centralwidget);
        house_min_input->setObjectName(QString::fromUtf8("house_min_input"));
        house_min_input->setGeometry(QRect(320, 170, 91, 21));
        house_max_input = new QTextEdit(centralwidget);
        house_max_input->setObjectName(QString::fromUtf8("house_max_input"));
        house_max_input->setGeometry(QRect(420, 170, 91, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 10, 141, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 0, 171, 31));
        customer_input = new QTextEdit(centralwidget);
        customer_input->setObjectName(QString::fromUtf8("customer_input"));
        customer_input->setGeometry(QRect(200, 50, 121, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 10, 171, 31));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 20, 121, 31));
        fund_input = new QTextEdit(centralwidget);
        fund_input->setObjectName(QString::fromUtf8("fund_input"));
        fund_input->setGeometry(QRect(50, 50, 121, 21));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(340, 0, 171, 31));
        refund_input = new QTextEdit(centralwidget);
        refund_input->setObjectName(QString::fromUtf8("refund_input"));
        refund_input->setGeometry(QRect(340, 50, 121, 21));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(340, 10, 171, 31));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(340, 20, 171, 31));
        car_max_input = new QTextEdit(centralwidget);
        car_max_input->setObjectName(QString::fromUtf8("car_max_input"));
        car_max_input->setGeometry(QRect(420, 200, 91, 21));
        car_min_input = new QTextEdit(centralwidget);
        car_min_input->setObjectName(QString::fromUtf8("car_min_input"));
        car_min_input->setGeometry(QRect(320, 200, 91, 21));
        car_cost_input = new QTextEdit(centralwidget);
        car_cost_input->setObjectName(QString::fromUtf8("car_cost_input"));
        car_cost_input->setGeometry(QRect(120, 200, 91, 21));
        car_duration_input = new QTextEdit(centralwidget);
        car_duration_input->setObjectName(QString::fromUtf8("car_duration_input"));
        car_duration_input->setGeometry(QRect(220, 200, 91, 21));
        health_max_input = new QTextEdit(centralwidget);
        health_max_input->setObjectName(QString::fromUtf8("health_max_input"));
        health_max_input->setGeometry(QRect(420, 230, 91, 21));
        health_cost_input = new QTextEdit(centralwidget);
        health_cost_input->setObjectName(QString::fromUtf8("health_cost_input"));
        health_cost_input->setGeometry(QRect(120, 230, 91, 21));
        health_duration_input = new QTextEdit(centralwidget);
        health_duration_input->setObjectName(QString::fromUtf8("health_duration_input"));
        health_duration_input->setGeometry(QRect(220, 230, 91, 21));
        health_min_input = new QTextEdit(centralwidget);
        health_min_input->setObjectName(QString::fromUtf8("health_min_input"));
        health_min_input->setGeometry(QRect(320, 230, 91, 21));
        update_house = new QPushButton(centralwidget);
        update_house->setObjectName(QString::fromUtf8("update_house"));
        update_house->setGeometry(QRect(530, 170, 91, 32));
        update_car = new QPushButton(centralwidget);
        update_car->setObjectName(QString::fromUtf8("update_car"));
        update_car->setGeometry(QRect(530, 200, 91, 32));
        update_health = new QPushButton(centralwidget);
        update_health->setObjectName(QString::fromUtf8("update_health"));
        update_health->setGeometry(QRect(530, 230, 91, 32));
        house_sold_output = new QTextBrowser(centralwidget);
        house_sold_output->setObjectName(QString::fromUtf8("house_sold_output"));
        house_sold_output->setGeometry(QRect(130, 350, 91, 31));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(230, 310, 91, 16));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(330, 310, 91, 16));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(130, 310, 91, 16));
        house_refund_output = new QTextBrowser(centralwidget);
        house_refund_output->setObjectName(QString::fromUtf8("house_refund_output"));
        house_refund_output->setGeometry(QRect(230, 350, 91, 31));
        house_income_output = new QTextBrowser(centralwidget);
        house_income_output->setObjectName(QString::fromUtf8("house_income_output"));
        house_income_output->setGeometry(QRect(330, 350, 91, 31));
        car_income_output = new QTextBrowser(centralwidget);
        car_income_output->setObjectName(QString::fromUtf8("car_income_output"));
        car_income_output->setGeometry(QRect(330, 390, 91, 31));
        car_refund_output = new QTextBrowser(centralwidget);
        car_refund_output->setObjectName(QString::fromUtf8("car_refund_output"));
        car_refund_output->setGeometry(QRect(230, 390, 91, 31));
        car_sold_output = new QTextBrowser(centralwidget);
        car_sold_output->setObjectName(QString::fromUtf8("car_sold_output"));
        car_sold_output->setGeometry(QRect(130, 390, 91, 31));
        health_income_output = new QTextBrowser(centralwidget);
        health_income_output->setObjectName(QString::fromUtf8("health_income_output"));
        health_income_output->setGeometry(QRect(330, 430, 91, 31));
        health_refund_output = new QTextBrowser(centralwidget);
        health_refund_output->setObjectName(QString::fromUtf8("health_refund_output"));
        health_refund_output->setGeometry(QRect(230, 430, 91, 31));
        health_sold_output = new QTextBrowser(centralwidget);
        health_sold_output->setObjectName(QString::fromUtf8("health_sold_output"));
        health_sold_output->setGeometry(QRect(130, 430, 91, 31));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 350, 61, 16));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 390, 91, 16));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 430, 91, 16));
        current_fund_output = new QTextBrowser(centralwidget);
        current_fund_output->setObjectName(QString::fromUtf8("current_fund_output"));
        current_fund_output->setGeometry(QRect(570, 360, 141, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(570, 330, 111, 16));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(480, 10, 141, 16));
        tax_input = new QTextEdit(centralwidget);
        tax_input->setObjectName(QString::fromUtf8("tax_input"));
        tax_input->setGeometry(QRect(480, 50, 121, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        play_month->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\274\320\265\321\201\321\217\321\206", nullptr));
        start_game->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\226\320\270\320\273\320\270\321\211\320\265", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202\320\276\320\262\321\213\320\271 \320\272\320\260\320\277\320\270\321\202\320\260\320\273", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\262\320\276\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\271", nullptr));
        update_house->setText(QCoreApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        update_car->setText(QCoreApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        update_health->setText(QCoreApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\321\213\320\273\321\214", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\275\320\276", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\226\320\270\320\273\320\270\321\211\320\265", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\272\320\260\320\277\320\270\321\202\320\260\320\273", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
