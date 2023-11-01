#include "carddialog.h"
#include "ui_carddialog.h"

cardDialog::cardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardDialog)
{
    ui->setupUi(this);
}

cardDialog::~cardDialog()
{
    delete ui;
}
