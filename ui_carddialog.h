/********************************************************************************
** Form generated from reading UI file 'carddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDDIALOG_H
#define UI_CARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cardDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_back;
    QPushButton *pushButton_back_2;

    void setupUi(QDialog *cardDialog)
    {
        if (cardDialog->objectName().isEmpty())
            cardDialog->setObjectName(QStringLiteral("cardDialog"));
        cardDialog->resize(400, 300);
        label = new QLabel(cardDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 151, 41));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 127);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(cardDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 51, 41));
        pushButton_2 = new QPushButton(cardDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 80, 51, 41));
        pushButton_3 = new QPushButton(cardDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(160, 80, 51, 41));
        pushButton_4 = new QPushButton(cardDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 80, 51, 41));
        pushButton_5 = new QPushButton(cardDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 80, 51, 41));
        pushButton_6 = new QPushButton(cardDialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 140, 51, 41));
        pushButton_7 = new QPushButton(cardDialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(90, 140, 51, 41));
        pushButton_8 = new QPushButton(cardDialog);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(160, 140, 51, 41));
        pushButton_9 = new QPushButton(cardDialog);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(230, 140, 51, 41));
        pushButton_10 = new QPushButton(cardDialog);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(300, 140, 51, 41));
        pushButton_back = new QPushButton(cardDialog);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(290, 250, 80, 24));
        pushButton_back_2 = new QPushButton(cardDialog);
        pushButton_back_2->setObjectName(QStringLiteral("pushButton_back_2"));
        pushButton_back_2->setGeometry(QRect(20, 250, 80, 24));

        retranslateUi(cardDialog);

        QMetaObject::connectSlotsByName(cardDialog);
    } // setupUi

    void retranslateUi(QDialog *cardDialog)
    {
        cardDialog->setWindowTitle(QApplication::translate("cardDialog", "Dialog", 0));
        label->setText(QApplication::translate("cardDialog", "\351\200\211\346\213\251\350\275\246\344\275\215\345\274\271\345\207\272\347\225\214\351\235\242", 0));
        pushButton->setText(QApplication::translate("cardDialog", "1", 0));
        pushButton_2->setText(QApplication::translate("cardDialog", "2", 0));
        pushButton_3->setText(QApplication::translate("cardDialog", "3", 0));
        pushButton_4->setText(QApplication::translate("cardDialog", "4", 0));
        pushButton_5->setText(QApplication::translate("cardDialog", "5", 0));
        pushButton_6->setText(QApplication::translate("cardDialog", "6", 0));
        pushButton_7->setText(QApplication::translate("cardDialog", "7", 0));
        pushButton_8->setText(QApplication::translate("cardDialog", "8", 0));
        pushButton_9->setText(QApplication::translate("cardDialog", "9", 0));
        pushButton_10->setText(QApplication::translate("cardDialog", "10", 0));
        pushButton_back->setText(QApplication::translate("cardDialog", "\350\277\224\345\233\236", 0));
        pushButton_back_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cardDialog: public Ui_cardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDDIALOG_H
