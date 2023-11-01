/********************************************************************************
** Form generated from reading UI file 'carspace.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSPACE_H
#define UI_CARSPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarSpace
{
public:
    QPushButton *pb_back;
    QPushButton *pb1;
    QPushButton *pb2;
    QPushButton *pb3;
    QPushButton *pb4;
    QPushButton *pb5;
    QPushButton *pb6;
    QPushButton *pb7;
    QPushButton *pb8;
    QPushButton *pb9;
    QPushButton *pb10;

    void setupUi(QWidget *CarSpace)
    {
        if (CarSpace->objectName().isEmpty())
            CarSpace->setObjectName(QStringLiteral("CarSpace"));
        CarSpace->resize(400, 300);
        pb_back = new QPushButton(CarSpace);
        pb_back->setObjectName(QStringLiteral("pb_back"));
        pb_back->setGeometry(QRect(10, 270, 80, 24));
        pb1 = new QPushButton(CarSpace);
        pb1->setObjectName(QStringLiteral("pb1"));
        pb1->setGeometry(QRect(30, 30, 51, 81));
        pb2 = new QPushButton(CarSpace);
        pb2->setObjectName(QStringLiteral("pb2"));
        pb2->setGeometry(QRect(90, 30, 51, 81));
        pb3 = new QPushButton(CarSpace);
        pb3->setObjectName(QStringLiteral("pb3"));
        pb3->setGeometry(QRect(160, 30, 51, 81));
        pb4 = new QPushButton(CarSpace);
        pb4->setObjectName(QStringLiteral("pb4"));
        pb4->setGeometry(QRect(230, 30, 51, 81));
        pb5 = new QPushButton(CarSpace);
        pb5->setObjectName(QStringLiteral("pb5"));
        pb5->setGeometry(QRect(300, 30, 51, 81));
        pb6 = new QPushButton(CarSpace);
        pb6->setObjectName(QStringLiteral("pb6"));
        pb6->setGeometry(QRect(30, 130, 51, 81));
        pb7 = new QPushButton(CarSpace);
        pb7->setObjectName(QStringLiteral("pb7"));
        pb7->setGeometry(QRect(90, 130, 51, 81));
        pb8 = new QPushButton(CarSpace);
        pb8->setObjectName(QStringLiteral("pb8"));
        pb8->setGeometry(QRect(160, 130, 51, 81));
        pb9 = new QPushButton(CarSpace);
        pb9->setObjectName(QStringLiteral("pb9"));
        pb9->setGeometry(QRect(230, 130, 51, 81));
        pb10 = new QPushButton(CarSpace);
        pb10->setObjectName(QStringLiteral("pb10"));
        pb10->setGeometry(QRect(300, 130, 51, 81));

        retranslateUi(CarSpace);

        QMetaObject::connectSlotsByName(CarSpace);
    } // setupUi

    void retranslateUi(QWidget *CarSpace)
    {
        CarSpace->setWindowTitle(QApplication::translate("CarSpace", "Form", 0));
        pb_back->setText(QApplication::translate("CarSpace", "\350\277\224\345\233\236", 0));
        pb1->setText(QApplication::translate("CarSpace", "1", 0));
        pb2->setText(QApplication::translate("CarSpace", "2", 0));
        pb3->setText(QApplication::translate("CarSpace", "3", 0));
        pb4->setText(QApplication::translate("CarSpace", "4", 0));
        pb5->setText(QApplication::translate("CarSpace", "5", 0));
        pb6->setText(QApplication::translate("CarSpace", "6", 0));
        pb7->setText(QApplication::translate("CarSpace", "7", 0));
        pb8->setText(QApplication::translate("CarSpace", "8", 0));
        pb9->setText(QApplication::translate("CarSpace", "9", 0));
        pb10->setText(QApplication::translate("CarSpace", "10", 0));
    } // retranslateUi

};

namespace Ui {
    class CarSpace: public Ui_CarSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSPACE_H
