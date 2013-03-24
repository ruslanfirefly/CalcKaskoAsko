#include "cascousinginfodialog.h"
#include "ui_cascousinginfodialog.h"
#include "printer.h"
#include <QSqlTableModel>
#include "database.h"

CascoUsingInfoDialog::CascoUsingInfoDialog(OsagoData* d, QWidget *parent) :
    QDialog(parent),
     ui(new Ui::CascoUsingInfoDialog)
{
    ui->setupUi(this);
    data = d;
    currentDrivers = maxDrivers;
    currentDateIntervals = maxDateIntervals;
    connect(ui->hideDriverButton, SIGNAL(clicked()),this, SLOT(hideDriver()));
    connect(ui->showDriverButton, SIGNAL(clicked()), this, SLOT(showDriver()));
    connect(ui->constDriversButton, SIGNAL(toggled(bool)), this, SLOT(setUnlimDriversEnabled(bool)));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(fillData()));
    connect(ui->prevButton, &QPushButton::clicked, [this](){ fillData(); emit this->prev(1);} );
    connect(ui->nextButton, &QPushButton::clicked, [this](){ fillData(); emit this->next(1); } );
    ui->constDriversButton->setChecked(true);
    this->resize(minimumSize());
    fillComboBoxes();
    fillFields();
    on_compareWithUsing_stateChanged(ui->compareWithUsing->checkState());
    while(currentDrivers != 1)
    {
        hideDriver();
    }
    while(currentDateIntervals != 1)
    {
        on_delTimeButton_clicked();
    }
}
CascoUsingInfoDialog::~CascoUsingInfoDialog()
{
    delete ui;
}
void CascoUsingInfoDialog::hideDriver()
{
    if(currentDrivers > 1) setTablwRowItemVisible(false, currentDrivers--, ui->driversGridLayout);
}

void CascoUsingInfoDialog::showDriver()
{
    if(currentDrivers < maxDrivers) setTablwRowItemVisible(true, ++currentDrivers, ui->driversGridLayout);
}

void CascoUsingInfoDialog::setDriverVisible(bool, int)
{

}

void CascoUsingInfoDialog::setTablwRowItemVisible(bool visible, int row , QGridLayout* grid)
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
void CascoUsingInfoDialog::setTablwRowItemEnable(bool enable, int row, QGridLayout *grid)
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

void CascoUsingInfoDialog::on_addTimeButton_clicked()
{
    if(currentDateIntervals < maxDateIntervals) setTablwRowItemVisible(true, ++currentDateIntervals, ui->timeGridLayout);
}

void CascoUsingInfoDialog::on_delTimeButton_clicked()
{
    if(currentDateIntervals > 1 ) setTablwRowItemVisible(false, currentDateIntervals--, ui->timeGridLayout);
}

void CascoUsingInfoDialog::setUnlimDriversEnabled(bool enabled)
{
    ui->showDriverButton->setEnabled(enabled);
    ui->hideDriverButton->setEnabled(enabled);
    for(int row = 0; row < ui->driversGridLayout->rowCount(); ++row )
    {
        setTablwRowItemEnable(enabled, row, ui->driversGridLayout);
    }
}
void CascoUsingInfoDialog::fillFields()
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
void CascoUsingInfoDialog::fillData()
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

    data->otherInfo = ui->otherInfoLineEdit->text();
    data->notes = ui->notesLineEdit->text();
    data->polisNum = ui->polisNumLineEdit->text();
    data->polisSerial = ui->polisSerialLineEdit->text();

    data->agent = ui->agentsComboBox->model()->data(
                ui->agentsComboBox->model()->index(ui->comboBox->view()->currentIndex().row(), 1)
                ).toString();
}

void CascoUsingInfoDialog::fillComboBoxes()
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

void CascoUsingInfoDialog::on_printRequest_clicked()
{

}

void CascoUsingInfoDialog::on_compareWithUsing_stateChanged(int state)
{

    if(QWidget* s = qobject_cast<QWidget*>(sender()))
    {
        s->setEnabled(true);
    }    
    for(int row = 0; row < ui->timeGridLayout->rowCount(); ++row )
    {
        if(state == Qt::Checked)
        {
            setTablwRowItemEnable(true, row, ui->timeGridLayout);
            ui->addTimeButton->setEnabled(true);
            ui->delTimeButton->setEnabled(true);
        }
        else
        {
            setTablwRowItemEnable(false, row, ui->timeGridLayout);
            ui->addTimeButton->setEnabled(false);
            ui->delTimeButton->setEnabled(false);
        }
    }

}
