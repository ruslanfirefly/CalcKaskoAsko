#include "osagousinginfoform.h"
#include "ui_osagousinginfoform.h"
#include "printer.h"
#include <QSqlTableModel>
#include "database.h"
OsagoUsingInfoForm::OsagoUsingInfoForm(OsagoData* d, QWidget *parent) :
    QDialog(parent),
     ui(new Ui::OsagoUsingInfoForm)
{
    ui->setupUi(this);
    data = d;
    currentDrivers = maxDrivers;
    currentDateIntervals = maxDateIntervals;
    connect(ui->hideDriverButton, SIGNAL(clicked()),this, SLOT(hideDriver()));
    connect(ui->showDriverButton, SIGNAL(clicked()), this, SLOT(showDriver()));
    connect(ui->constDriversButton, SIGNAL(toggled(bool)), this, SLOT(setUnlimDriversEnabled(bool)));
    connect(ui->lastOsagoContractCheckBox, SIGNAL(toggled(bool)), this, SLOT(lastOsagoContractEnable(bool)));
    connect(ui->prevButton, SIGNAL(clicked()), this, SIGNAL(prev()));
    connect(ui->printBlank, SIGNAL(clicked()), this, SIGNAL(printBlank()));
    connect(ui->printRequest, SIGNAL(clicked()), this, SIGNAL(printRequest()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(fillData()));
    connect(ui->printBlank, SIGNAL(clicked()), this, SLOT(fillData()));
    connect(ui->printRequest, SIGNAL(clicked()), this, SLOT(fillData()));
    ui->constDriversButton->setChecked(true);
    lastOsagoContractEnable(false);
    this->resize(minimumSize());
    fillComboBoxes();
    fillFields();
    on_compareWithUsing_stateChanged(ui->compareWithUsing->checkState());
}
OsagoUsingInfoForm::~OsagoUsingInfoForm()
{
    delete ui;
}
void OsagoUsingInfoForm::hideDriver()
{
    if(currentDrivers > 1) setTablwRowItemVisible(false, currentDrivers--, ui->driversGridLayout);
}

void OsagoUsingInfoForm::showDriver()
{
    if(currentDrivers < maxDrivers) setTablwRowItemVisible(true, ++currentDrivers, ui->driversGridLayout);
}

void OsagoUsingInfoForm::setDriverVisible(bool, int)
{

}

void OsagoUsingInfoForm::setTablwRowItemVisible(bool visible, int row , QGridLayout* grid)
{
    for(int column = 0; column < grid->columnCount(); ++column)
    {
        QLayoutItem* item = grid->itemAtPosition(row, column);
        if(QWidget* w = item->widget())
        {
            w->setVisible(visible);
        }
    }
    resize(minimumSize());
}
void OsagoUsingInfoForm::setTablwRowItemEnable(bool enable, int row, QGridLayout *grid)
{
    for(int column = 0; column < grid->columnCount(); ++column)
    {
        QLayoutItem* item = grid->itemAtPosition(row, column);
        if(QWidget* w = item->widget())
        {
            w->setEnabled(enable);
        }
    }
}

void OsagoUsingInfoForm::on_addTimeButton_clicked()
{
    if(currentDateIntervals < maxDateIntervals) setTablwRowItemVisible(true, ++currentDateIntervals, ui->timeGridLayout);
}

void OsagoUsingInfoForm::on_delTimeButton_clicked()
{
    if(currentDateIntervals > 1 ) setTablwRowItemVisible(false, currentDateIntervals--, ui->timeGridLayout);
}

void OsagoUsingInfoForm::setUnlimDriversEnabled(bool enabled)
{
    ui->showDriverButton->setEnabled(enabled);
    ui->hideDriverButton->setEnabled(enabled);
    for(int row = 0; row < ui->driversGridLayout->rowCount(); ++row )
    {
        setTablwRowItemEnable(enabled, row, ui->driversGridLayout);
    }
}
void OsagoUsingInfoForm::lastOsagoContractEnable(bool enable)
{
    for(int row = 1; row < ui->lastOsagoGridLayout->rowCount(); ++row)
    {
        for(int column = 0; column < ui->lastOsagoGridLayout->columnCount(); ++column)
        {
            ui->lastOsagoGridLayout->itemAtPosition(row, column)->widget()->setEnabled(enable);
        }
    }
}
void OsagoUsingInfoForm::fillFields()
{
    switch(data->dCount)
    {
    case OsagoData::LimitDrivers:
        ui->constDriversButton->setChecked(true);
        break;
    case OsagoData::UnlimitedDrivers:
        ui->unlimDriversButton->setChecked(true);
        break;
    }
    for(int i = 0; i < data->drivers.count(); ++i)
    {
        qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i+1, 0)->widget())->setText(data->drivers[i].fio);
        qobject_cast<QDateEdit*>(ui->driversGridLayout->itemAtPosition(i+1, 1)->widget())->setDate(data->drivers[i].birthday);
        qobject_cast<QComboBox*>(ui->driversGridLayout->itemAtPosition(i+1, 2)->widget())->setCurrentIndex(data->drivers[i].sex);
        qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i+1, 3)->widget())->setText(data->drivers[i].driverLicence);
        qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i+1, 4)->widget())->setText(data->drivers[i].stage);
        qobject_cast<QComboBox*>(ui->driversGridLayout->itemAtPosition(i+1, 5)->widget())->setCurrentIndex(data->drivers[i].dClass);
        qobject_cast<QSpinBox*>(ui->driversGridLayout->itemAtPosition(i+1, 6)->widget())->setValue(data->drivers[i].countOfIncidents);
    }
    ui->fromInsDate->setDate(data->from);
    ui->toInsDate->setDate(data->to);

    for(int i = 0; i< data->usingPeriods.count(); ++i)
    {
        qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(i+1, 1)->widget())->setDate(data->usingPeriods[i].first);
        qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(i+1, 4)->widget())->setDate(data->usingPeriods[i].second);
    }
    ui->lastOsagoContractCheckBox->setChecked(data->hasLastOsago);
    ui->lastOsagoCompany->setText(data->lastOsagoCompany);
    ui->lastOsagoNum->setText(data->lastOsagoNum);
    ui->lastOsagoSerial->setText(data->lastOsagoSerial);
    ui->otherInfoLineEdit->setText(data->otherInfo);
    ui->notesLineEdit->setText(data->notes);
    ui->polisNumLineEdit->setText(data->polisNum);
    ui->polisSerialLineEdit->setText(data->polisSerial);
    QSqlQueryModel* agentsModel = new QSqlQueryModel(this);
    agentsModel->setQuery(
                "SELECT  second_name || \" \" || first_name || \" \" || third_name  ||"
                "\"  (договор №\" || number || \" от \" ||date || \")\","
                " second_name || \" \" || first_name || \" \" || third_name from agents",
                QSqlDatabase::database(dataBase::agentsDb.connectionName())
                );
    ui->agentsComboBox->setModel(agentsModel);
    ui->agentsComboBox->view()->setCurrentIndex(agentsModel->index(0, 1));
}
void OsagoUsingInfoForm::fillData()
{
    data->dCount = ui->constDriversButton->isChecked() ? OsagoData::LimitDrivers : OsagoData::UnlimitedDrivers;
    data->drivers.clear();
    data->usingPeriods.clear();
    for(int i = 1; i<=currentDrivers; ++i)
    {
        data->drivers.push_back(DriverInfo());
        data->drivers[i-1].fio = qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i, 0)->widget())->text();
        data->drivers[i-1].birthday = qobject_cast<QDateEdit*>(ui->driversGridLayout->itemAtPosition(i, 1)->widget())->date();
        data->drivers[i-1].sex = static_cast<DriverInfo::Sexes>(qobject_cast<QComboBox*>(ui->driversGridLayout->itemAtPosition(i, 2)->widget())->currentIndex());
        data->drivers[i-1].driverLicence = qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i, 3)->widget())->text();
        data->drivers[i-1].stage = qobject_cast<QLineEdit*>(ui->driversGridLayout->itemAtPosition(i, 4)->widget())->text();
        data->drivers[i-1].dClass = qobject_cast<QComboBox*>(ui->driversGridLayout->itemAtPosition(i, 5)->widget())->currentIndex();
        data->drivers[i-1].countOfIncidents = qobject_cast<QSpinBox*>(ui->driversGridLayout->itemAtPosition(i, 6)->widget())->value();
    }
    for(int i = 1; i<=currentDateIntervals; ++i)
    {
        data->usingPeriods.push_back(QPair<QDate, QDate>());
        data->usingPeriods[i-1].first = qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(i, 1)->widget())->date();

        data->usingPeriods[i-1].second = qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(i, 4)->widget())->date();
    }
    if(ui->compareWithUsing->isChecked())
    {
        //qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(1, 1)->widget())->setDate(ui->fromInsDate->date());
        //qobject_cast<QDateEdit*>(ui->timeGridLayout->itemAtPosition(1, 4)->widget())->setDate(ui->toInsDate->date());
        data->usingPeriods.clear();
        data->usingPeriods.push_back(QPair<QDate, QDate>());
        data->usingPeriods.first().first = ui->fromInsDate->date();
        data->usingPeriods.first().second = ui->toInsDate->date();
    }
    data->hasLastOsago = ui->lastOsagoContractCheckBox->isChecked();
    data->lastOsagoCompany = ui->lastOsagoCompany->text();
    data->lastOsagoNum = ui->lastOsagoNum->text();
    data->lastOsagoSerial = ui->lastOsagoSerial->text();
    data->otherInfo = ui->otherInfoLineEdit->text();
    data->notes = ui->notesLineEdit->text();
    data->polisNum = ui->polisNumLineEdit->text();
    data->polisSerial = ui->polisSerialLineEdit->text();
    data->from = ui->fromInsDate->date();
    data->to = ui->toInsDate->date();
    data->agent = ui->agentsComboBox->model()->data(
                ui->agentsComboBox->model()->index(ui->comboBox->view()->currentIndex().row(), 1)
                ).toString();
}

void OsagoUsingInfoForm::fillComboBoxes()
{
    for(int row = 1; row < ui->driversGridLayout->rowCount(); ++row)
    {
        QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database("calc.db"));
        model->setTable("classes");
        model->select();
        QComboBox* classesComboBox = qobject_cast<QComboBox*>(ui->driversGridLayout->itemAtPosition(row, 5)->widget());
        classesComboBox->setModel(model);
        classesComboBox->setModelColumn(1);
        classesComboBox->view()->setCurrentIndex(model->index(0, 1));
    }
}

void OsagoUsingInfoForm::on_printRequest_clicked()
{

}

void OsagoUsingInfoForm::on_compareWithUsing_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        ui->usingPeriodsGroupBox->setEnabled(false);        
    }
    else
    {
        ui->usingPeriodsGroupBox->setEnabled(true);
    }
}
