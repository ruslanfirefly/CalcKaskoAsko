#include "osagoblankdataform.h"
#include "ui_osagoblankdataform.h"
#include "dataObjects.h"
OsagoBlankDataForm::OsagoBlankDataForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OsagoBlankDataForm)
{
    ui->setupUi(this);
    connect(this->ui->nextButton, SIGNAL(clicked()), this, SLOT(sendNext()));
    connect(this->ui->prevPushButton, SIGNAL(clicked()), this, SIGNAL(prev()));
}

OsagoBlankDataForm::~OsagoBlankDataForm()
{
    delete ui;
}
OsagoBlankDataForm::OsagoBlankDataForm(Driver *d, Driver::DriverTypes dType, bool *insurancerIsOwner, QWidget *parent) : OsagoBlankDataForm(parent)
{
    data = d;
    isOwner = insurancerIsOwner;
    fillFields();
    hideFields(dType);
    driverType = dType;
}
void OsagoBlankDataForm::sendNext()
{
    fillData();
    (ui->insurancerIsOwner->isChecked() && driverType==Driver::Insurancer) ? (emit next(2)) : (emit next(1));
}
void OsagoBlankDataForm::hideFields(Driver::DriverTypes dType)
{
    ui->insurancerIsOwner->setVisible(dType == Driver::Insurancer);
    ui->phone->setVisible(dType == Driver::Insurancer);
    ui->phoneLabel->setVisible(dType == Driver::Insurancer);
}
void OsagoBlankDataForm::fillFields()
{
    ui->insurancerIsOwner->setChecked(*isOwner);
    ui->fioLineEdit->setText(data->fio);
    ui->dateInnLineEdit->setText(QString::number(data->inn));
    ui->serialLineEdit->setText(data->ser);
    ui->numberLineEdit->setText(data->number);
    ui->typeLineEdit->setText(data->documentType);
    ui->index->setText(data->addr.index);
    ui->country->setText(data->addr.country);
    ui->state->setText(data->addr.state);
    ui->city->setText(data->addr.city);
    ui->street->setText(data->addr.street);
    ui->house->setText(data->addr.house);
    ui->corp->setText(data->addr.corp);
    ui->flat->setText(data->addr.flat);
    ui->phone->setText(data->phone);
}

void OsagoBlankDataForm::fillData()
{
    (*isOwner) = ui->insurancerIsOwner->isChecked();
    data->fio = ui->fioLineEdit->text();
    data->inn = ui->dateInnLineEdit->text().toULongLong();
    data->ser = ui->serialLineEdit->text();
    data->number = ui->numberLineEdit->text();
    data->documentType = ui->typeLineEdit->text();
    data->addr.index = ui->index->text();
    data->addr.country = ui->country->text();
    data->addr.state = ui->state->text();
    data->addr.city = ui->city->text();
    data->addr.street = ui->street->text();
    data->addr.house = ui->house->text();
    data->addr.corp = ui->corp->text();
    data->addr.flat = ui->flat->text();
    data->phone = ui->phone->text();
}
