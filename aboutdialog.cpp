#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    setFixedSize(width(), height());

    ui->lblIcon->setPixmap(QPixmap(":/images/system.png"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
