#include "parkingspace.h"
#include "ui_parkingspace.h"

Parkingspace::Parkingspace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parkingspace)
{
    ui->setupUi(this);
}

Parkingspace::~Parkingspace()
{
    delete ui;
}

void Parkingspace::on_pb_exit_clicked()
{

}

