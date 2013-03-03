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
    connect(this->ui->nextButton, SIGNAL(clicked()), this, SLOT(fillData()));
    connect(this->ui->prevPushButton, SIGNAL(clicked()), this, SLOT(fillData()));
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
    on_checkBox_stateChanged(ui->checkBox->checkState());
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
    ui->dateInnLineEdit->setText(data->inn);
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
    ui->birthday->setDate(data->birthday);
    ui->checkBox->setChecked(!data->fizik);
}

void OsagoBlankDataForm::fillData()
{
    (*isOwner) = ui->insurancerIsOwner->isChecked();
    data->fio = ui->fioLineEdit->text();
    data->inn = ui->dateInnLineEdit->text();
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
    data->birthday = ui->birthday->date();
    data->fizik = !ui->checkBox->isChecked();

}

void OsagoBlankDataForm::on_checkBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        ui->insurancerNameLabel->setText(tr("Наименование юридического лица"));
        ui->dateInnLabel->setText(tr("ИНН юридического лица"));
        ui->birthday->hide();
        ui->dateInnLineEdit->show();
    }
    else
    {
         ui->insurancerNameLabel->setText(tr("Фамилия, имя, отчество гражданина"));
         ui->dateInnLabel->setText(tr("Дата рождения гражданина"));
         ui->birthday->show();
         ui->dateInnLineEdit->hide();
    }
}
