#include "osagotsblank.h"
#include "ui_osagotsblank.h"
#include <QSqlTableModel>
OsagoTsBlank::OsagoTsBlank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OsagoTsBlank)
{
    ui->setupUi(this);
    connect(ui->nextButton, SIGNAL(clicked()), this, SIGNAL(next()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(sendPrev()));
    on_tsTypeComboBox_activated(ui->tsTypeComboBox->currentIndex());
}
OsagoTsBlank::OsagoTsBlank(ts *d, bool *insurancerIsOwner, QWidget *parent) : OsagoTsBlank(parent)
{
    isOwner = insurancerIsOwner;
    data = d;
    fillFields();
}

OsagoTsBlank::~OsagoTsBlank()
{
    delete ui;
}
void OsagoTsBlank::sendPrev()
{
    (*isOwner) ? (emit prev(2)) : (emit prev(1));
}
void OsagoTsBlank::fillFields()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database("my_db.sqlite"));
    model->setTable("classes");
    model->select();
    ui->classesComboBox->setModel(model);
    ui->classesComboBox->setModelColumn(1);
    ui->classesComboBox->view()->setCurrentIndex(model->index(0, 1));
    ui->modelLineEdit->setText(data->model);
    ui->vinLineEdit->setText(data->vin);
    ui->powerSpinBox->setValue(data->power);
    ui->passengersCountSpinBox->setValue(data->passengersCount);
    switch(data->pType)
    {
    case ts::hp:
        ui->hpRadioButton->setChecked(true);
    case ts::kWt:
        ui->kWtRadioButton->setChecked(true);
    }
    ui->tsTypeComboBox->setCurrentIndex(data->tCat);
    ui->yearSpinBox->setValue(data->year);
    ui->mass->setValue(data->mass);
    ui->shassiLineEdit->setText(data->shassi);
    ui->trackLineEdit->setText(data->track);
    ui->serialLineEdit->setText(data->serial);
    ui->numLineEdit->setText(data->number);
}


void OsagoTsBlank::on_tsTypeComboBox_activated(int index)
{
    ui->mass->hide();
    ui->passengersCountSpinBox->hide();
    ui->massLabel->hide();
    ui->countLabel->hide();
    switch(index)
    {
    case ts::C:
        ui->mass->show();
        ui->massLabel->show();
        break;
    case ts::D:
        ui->passengersCountSpinBox->show();
        ui->countLabel->show();
        break;
    }
}
