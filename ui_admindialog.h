/********************************************************************************
** Form generated from reading UI file 'admindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDIALOG_H
#define UI_ADMINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <keyborad.h>

QT_BEGIN_NAMESPACE

class Ui_adminDialog
{
public:
    QWidget *widget_2;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_password;
    QPushButton *pb_login;
    QPushButton *pb_back;
    QLabel *label;
    QWidget *widget;
    QLabel *label_2;
    QPushButton *pb_back2;
    QTableWidget *tableWidget;
    KeyBorad *widget_4;

    void setupUi(QDialog *adminDialog)
    {
        if (adminDialog->objectName().isEmpty())
            adminDialog->setObjectName(QStringLiteral("adminDialog"));
        adminDialog->resize(800, 480);
        widget_2 = new QWidget(adminDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 800, 480));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 255);"));
        lineEdit_account = new QLineEdit(widget_2);
        lineEdit_account->setObjectName(QStringLiteral("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(220, 90, 301, 51));
        lineEdit_account->setClearButtonEnabled(true);
        lineEdit_password = new QLineEdit(widget_2);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(220, 150, 301, 51));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setClearButtonEnabled(true);
        pb_login = new QPushButton(widget_2);
        pb_login->setObjectName(QStringLiteral("pb_login"));
        pb_login->setGeometry(QRect(220, 210, 111, 41));
        pb_back = new QPushButton(widget_2);
        pb_back->setObjectName(QStringLiteral("pb_back"));
        pb_back->setGeometry(QRect(410, 210, 111, 41));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 10, 391, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 481));
        widget->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 10, 211, 41));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        pb_back2 = new QPushButton(widget);
        pb_back2->setObjectName(QStringLiteral("pb_back2"));
        pb_back2->setGeometry(QRect(0, 10, 81, 31));
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 70, 661, 191));
        widget_4 = new KeyBorad(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 280, 800, 200));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 127);"));

        retranslateUi(adminDialog);

        QMetaObject::connectSlotsByName(adminDialog);
    } // setupUi

    void retranslateUi(QDialog *adminDialog)
    {
        adminDialog->setWindowTitle(QApplication::translate("adminDialog", "Dialog", 0));
        lineEdit_account->setPlaceholderText(QApplication::translate("adminDialog", "\350\264\246\345\217\267...", 0));
        lineEdit_password->setPlaceholderText(QApplication::translate("adminDialog", "\345\257\206\347\240\201...", 0));
        pb_login->setText(QApplication::translate("adminDialog", "\347\231\273\345\275\225", 0));
        pb_back->setText(QApplication::translate("adminDialog", "\350\277\224\345\233\236", 0));
        label->setText(QApplication::translate("adminDialog", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225\347\225\214\351\235\242", 0));
        label_2->setText(QApplication::translate("adminDialog", "\350\275\246\350\276\206\344\277\241\346\201\257", 0));
        pb_back2->setText(QApplication::translate("adminDialog", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class adminDialog: public Ui_adminDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDIALOG_H
