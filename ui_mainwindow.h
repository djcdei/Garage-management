/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_adv;
    QPushButton *pb_userlogin;
    QPushButton *pb_admlogin;
    QLabel *label_date;
    QLabel *label_title;
    QPushButton *pb_exit;
    QLabel *label_show;
    QFrame *line;
    QFrame *line_2;
    QPushButton *pb_L;
    QPushButton *pb_R;
    QLabel *label_11_title;
    QWidget *widget;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QWidget *widget_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_18;
    QPushButton *pb_weather;
    QLabel *label_weather;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_adv = new QLabel(centralwidget);
        label_adv->setObjectName(QStringLiteral("label_adv"));
        label_adv->setGeometry(QRect(310, 50, 271, 141));
        label_adv->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 255);"));
        label_adv->setAlignment(Qt::AlignCenter);
        pb_userlogin = new QPushButton(centralwidget);
        pb_userlogin->setObjectName(QStringLiteral("pb_userlogin"));
        pb_userlogin->setGeometry(QRect(620, 410, 81, 51));
        QFont font;
        font.setPointSize(7);
        pb_userlogin->setFont(font);
        pb_admlogin = new QPushButton(centralwidget);
        pb_admlogin->setObjectName(QStringLiteral("pb_admlogin"));
        pb_admlogin->setGeometry(QRect(530, 410, 81, 51));
        pb_admlogin->setFont(font);
        label_date = new QLabel(centralwidget);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setGeometry(QRect(590, 10, 201, 61));
        label_date->setStyleSheet(QStringLiteral(""));
        label_date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(310, 0, 251, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_title->setFont(font1);
        label_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_title->setAlignment(Qt::AlignCenter);
        pb_exit = new QPushButton(centralwidget);
        pb_exit->setObjectName(QStringLiteral("pb_exit"));
        pb_exit->setGeometry(QRect(710, 410, 81, 51));
        pb_exit->setFont(font);
        label_show = new QLabel(centralwidget);
        label_show->setObjectName(QStringLiteral("label_show"));
        label_show->setGeometry(QRect(10, 10, 281, 181));
        label_show->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 0);"));
        label_show->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 190, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(300, 0, 20, 481));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pb_L = new QPushButton(centralwidget);
        pb_L->setObjectName(QStringLiteral("pb_L"));
        pb_L->setGeometry(QRect(0, 200, 65, 35));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        pb_L->setFont(font2);
        pb_R = new QPushButton(centralwidget);
        pb_R->setObjectName(QStringLiteral("pb_R"));
        pb_R->setGeometry(QRect(240, 200, 65, 35));
        pb_R->setFont(font2);
        label_11_title = new QLabel(centralwidget);
        label_11_title->setObjectName(QStringLiteral("label_11_title"));
        label_11_title->setGeometry(QRect(70, 200, 165, 31));
        QFont font3;
        font3.setPointSize(9);
        label_11_title->setFont(font3);
        label_11_title->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 240, 301, 231));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 120, 41, 101));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(250, 120, 41, 101));
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 120, 41, 101));
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_9->setAlignment(Qt::AlignCenter);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 41, 101));
        label->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 120, 41, 101));
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 10, 41, 101));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 120, 41, 101));
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 41, 101));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 10, 41, 101));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 10, 41, 101));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 301, 231));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(130, 10, 41, 101));
        label_13->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(190, 10, 41, 101));
        label_14->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(250, 10, 41, 101));
        label_15->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_15->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(widget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 120, 41, 101));
        label_17->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(widget_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(190, 120, 41, 101));
        label_19->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(widget_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(250, 120, 41, 101));
        label_20->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_20->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 41, 101));
        label_11->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(70, 10, 41, 101));
        label_12->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 120, 41, 101));
        label_16->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_16->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(130, 120, 41, 101));
        label_18->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_18->setAlignment(Qt::AlignCenter);
        pb_weather = new QPushButton(centralwidget);
        pb_weather->setObjectName(QStringLiteral("pb_weather"));
        pb_weather->setGeometry(QRect(600, 20, 81, 41));
        label_weather = new QLabel(centralwidget);
        label_weather->setObjectName(QStringLiteral("label_weather"));
        label_weather->setGeometry(QRect(590, 70, 201, 121));
        label_weather->setFont(font3);
        label_weather->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 255);"));
        label_weather->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_adv->setText(QApplication::translate("MainWindow", "\345\271\277\345\221\212\346\212\225\346\224\276\347\211\214", 0));
        pb_userlogin->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267", 0));
        pb_admlogin->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", 0));
        label_date->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\227\266\351\227\264/\346\227\245\346\234\237", 0));
        label_title->setText(QApplication::translate("MainWindow", "\345\216\237\347\245\236\345\201\234\350\275\246\345\234\272", 0));
        pb_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        label_show->setText(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264\347\224\273\351\235\242", 0));
        pb_L->setText(QApplication::translate("MainWindow", "\343\200\212", 0));
        pb_R->setText(QApplication::translate("MainWindow", "\343\200\213", 0));
        label_11_title->setText(QApplication::translate("MainWindow", "\350\275\246\344\275\215\344\277\241\346\201\257", 0));
        label_7->setText(QApplication::translate("MainWindow", "7", 0));
        label_10->setText(QApplication::translate("MainWindow", "10", 0));
        label_9->setText(QApplication::translate("MainWindow", "9", 0));
        label->setText(QApplication::translate("MainWindow", "1", 0));
        label_6->setText(QApplication::translate("MainWindow", "6", 0));
        label_4->setText(QApplication::translate("MainWindow", "4", 0));
        label_8->setText(QApplication::translate("MainWindow", "8", 0));
        label_2->setText(QApplication::translate("MainWindow", "2", 0));
        label_5->setText(QApplication::translate("MainWindow", "5", 0));
        label_3->setText(QApplication::translate("MainWindow", "3", 0));
        label_13->setText(QApplication::translate("MainWindow", "13", 0));
        label_14->setText(QApplication::translate("MainWindow", "14", 0));
        label_15->setText(QApplication::translate("MainWindow", "15", 0));
        label_17->setText(QApplication::translate("MainWindow", "17", 0));
        label_19->setText(QApplication::translate("MainWindow", "19", 0));
        label_20->setText(QApplication::translate("MainWindow", "20", 0));
        label_11->setText(QApplication::translate("MainWindow", "11", 0));
        label_12->setText(QApplication::translate("MainWindow", "12", 0));
        label_16->setText(QApplication::translate("MainWindow", "16", 0));
        label_18->setText(QApplication::translate("MainWindow", "18", 0));
        pb_weather->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224", 0));
        label_weather->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\244\251\346\260\224", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
