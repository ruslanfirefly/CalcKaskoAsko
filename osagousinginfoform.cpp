#include "osagousinginfoform.h"
#include "ui_osagousinginfoform.h"
#include "printer.h"
OsagoUsingInfoForm::OsagoUsingInfoForm(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::OsagoUsingInfoForm)
{
    ui->setupUi(this);
    currentDrivers = maxDrivers;
    currentDateIntervals = maxDateIntervals;

    connect(ui->hideDriverButton, SIGNAL(clicked()),this, SLOT(hideDriver()));
    connect(ui->showDriverButton, SIGNAL(clicked()), this, SLOT(showDriver()));
    connect(ui->constDriversButton, SIGNAL(toggled(bool)), this, SLOT(setUnlimDriversEnabled(bool)));
    connect(ui->lastOsagoContractCheckBox, SIGNAL(toggled(bool)), this, SLOT(lastOsagoContractEnable(bool)));
    connect(ui->prevButton, SIGNAL(clicked()), this, SIGNAL(prev()));
    connect(ui->printBlank, SIGNAL(clicked()), this, SIGNAL(printBlank()));
    connect(ui->printRequest, SIGNAL(clicked()), this, SIGNAL(printRequest()));
    ui->constDriversButton->setChecked(true);
    lastOsagoContractEnable(false);
    this->resize(minimumSize());
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




void OsagoUsingInfoForm::on_printRequest_clicked()
{

}
