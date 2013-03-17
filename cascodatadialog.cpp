#include "cascodatadialog.h"
#include "ui_cascodatadialog.h"
#include <QShowEvent>
#include <QTimer>
CascoDataDialog::CascoDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CascoDataDialog)
{
    ui->setupUi(this);
    connect(ui->nextButton, &QPushButton::clicked, [this](){
        fillData();
        hide();
        emit next(1);
    });
    connect(ui->prevPushButton, &QPushButton::clicked, [this](){ fillData(); hide(); emit prev(1); });

    connect(ui->urCheckBox, SIGNAL(stateChanged(int)), this, SLOT(clientTypeChanged(int)));
    clientTypeChanged(Qt::Unchecked);
}

CascoDataDialog::~CascoDataDialog()
{
    delete ui;
}
CascoDataDialog::CascoDataDialog(CascoDialogType t, OsagoData *d, QWidget *parent) : CascoDataDialog(parent)
{
    data = d;
    switch (t) {
    case Owner:
        setWindowTitle(tr("Данные собственника"));
        ui->dTypeGroupBox->setTitle(tr("Собственник"));
        driver = &(data->owner);
        break;
    case Insurancer:
        setWindowTitle(tr("Данные страхователя"));
        ui->dTypeGroupBox->setTitle(tr("Страхователь"));
        driver = &(data->insurancer);
        break;
    case Profiter:
        setWindowTitle(tr("Данные выгодоприобретателя"));
        ui->dTypeGroupBox->setTitle(tr("Выгодоприобретатель"));
        driver = (&data->profiter);
        break;
    default:
        break;
    }
    dType = t;

    ui->profiter->setVisible(t == Insurancer);
    ui->insurancerIsOwner->setVisible(t == Insurancer);
}
void CascoDataDialog::showEvent(QShowEvent * e)
{
    if(e->spontaneous()) return;
    fillFields();
    switch (dType) {
    case Owner:
        if(data->insurancerIsOwner)
        {
            QTimer::singleShot(100, this, SLOT(hideAndNext()));

        }
        break;
    case Profiter:
        if(data->insurancerIsProfiter)
        {
            QTimer::singleShot(100, this, SLOT(hideAndNext()));

        }
        break;
    default:
        break;
    }
}
void CascoDataDialog::hideAndNext()
{
    emit next(1);
}

void CascoDataDialog::fillData()
{
    if(dType == Insurancer)
    {
        data->insurancerIsOwner = ui->insurancerIsOwner->isChecked();
        data->insurancerIsProfiter = ui->profiter->isChecked();
    }
    driver->fio = ui->fioLineEdit->text();
    driver->inn = ui->dateInnLineEdit->text();
    driver->ser = ui->serialLineEdit->text();
    driver->number = ui->numberLineEdit->text();
    driver->documentType = ui->typeLineEdit->text();
    driver->addr.index = ui->index->text();
    driver->addr.country = ui->country->text();
    driver->addr.state = ui->state->text();
    driver->addr.city = ui->city->text();
    driver->addr.street = ui->street->text();
    driver->addr.house = ui->house->text();
    driver->addr.corp = ui->corp->text();
    driver->addr.flat = ui->flat->text();
    driver->phone = ui->phone->text();
    driver->birthday = ui->birthday->date();
    driver->fizik = !ui->urCheckBox->isChecked();
}
void CascoDataDialog::fillFields()
{
    ui->insurancerIsOwner->setChecked(data->insurancerIsOwner);
    ui->profiter->setChecked(data->insurancerIsProfiter);
    ui->fioLineEdit->setText(driver->fio);
    ui->dateInnLineEdit->setText(driver->inn);
    ui->serialLineEdit->setText(driver->ser);
    ui->numberLineEdit->setText(driver->number);
    ui->typeLineEdit->setText(driver->documentType);
    ui->index->setText(driver->addr.index);
    ui->country->setText(driver->addr.country);
    ui->state->setText(driver->addr.state);
    ui->city->setText(driver->addr.city);
    ui->street->setText(driver->addr.street);
    ui->house->setText(driver->addr.house);
    ui->corp->setText(driver->addr.corp);
    ui->flat->setText(driver->addr.flat);
    ui->phone->setText(driver->phone);
    ui->birthday->setDate(driver->birthday);
    ui->urCheckBox->setChecked(!driver->fizik);
}
void CascoDataDialog::clientTypeChanged(int state)
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
