#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    setModal(true);
    setFixedSize(width(), height());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_btnSaveSettings_clicked()
{
    //FIXME
    qDebug() << "Saving settings - to do !";

    hide();
}
