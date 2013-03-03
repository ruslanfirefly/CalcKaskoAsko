#include "osagotsblank.h"
#include "ui_osagotsblank.h"
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <database.h>
OsagoTsBlank::OsagoTsBlank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OsagoTsBlank)
{
    ui->setupUi(this);
    connect(ui->nextButton, SIGNAL(clicked()), this, SIGNAL(next()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(fillData()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(sendPrev()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(fillData()));
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
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database("calc.db"));
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
    ui->documentDateEdit->setDate(data->documentDate);
    ui->isRentalCheckBox->setChecked(data->isRental);
    ui->usingTypeComboBox->setCurrentIndex(data->uType);
    ui->classesComboBox->setCurrentIndex(data->classOwner);
    ui->incidentsSpinBox->setValue(data->countOfIncidents);
    ui->documentTypeComboBox->setCurrentIndex(data->documentType);
    ui->gosNumber->setText(data->gosNumber);
}
void OsagoTsBlank::fillData()
{
    data->model = ui->modelLineEdit->text();
    data->vin = ui->vinLineEdit->text();
    data->power = ui->powerSpinBox->value();
    data->passengersCount = ui->passengersCountSpinBox->value();
    data->pType = ui->hpRadioButton->isChecked() ? ts::hp : ts::kWt;
    data->tCat = static_cast<ts::TsCategories>(ui->tsTypeComboBox->currentIndex());
    data->year = ui->yearSpinBox->value();
    data->mass = ui->mass->value();
    data->shassi = ui->shassiLineEdit->text();
    data->track = ui->trackLineEdit->text();
    data->serial = ui->serialLineEdit->text();
    data->number = ui->numLineEdit->text();
    data->documentDate = ui->documentDateEdit->date();
    data->isRental = ui->isRentalCheckBox->isChecked();
    data->uType = static_cast<ts::UsingType>(ui->usingTypeComboBox->currentIndex());
    data->classOwner = ui->classesComboBox->currentIndex();
    data->countOfIncidents = ui->incidentsSpinBox->value();
    data->documentType = static_cast<ts::DocumentTypes>(ui->documentTypeComboBox->currentIndex());
    data->gosNumber = ui->gosNumber->text();
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
