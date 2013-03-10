#include "osagocalcform.h"
#include "ui_osagocalcform.h"
#include <QSqlTableModel>
#include <QCompleter>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QVariantMap>
#include <calculatorosago.h>
#include "printer.h"
#include <QFile>
#include "osagoblankdataform.h"

osagoCalcForm::osagoCalcForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::osagoCalcForm)
{
    ui->setupUi(this);
    activateComboBoxes();
    createCompleter();
    connect(this->ui->nextButton, SIGNAL(clicked()), this, SIGNAL(next()));
    connect(ui->autoTypeComboBox, SIGNAL(activated(int)), this, SLOT(showFields(int)));
    connect(ui->regTypeComboBox, SIGNAL(activated(int)), this, SLOT(showPeriods(int)));
    showPeriods(ui->regTypeComboBox->currentIndex());
}
osagoCalcForm::osagoCalcForm(OsagoData* d,  QWidget *parent) : osagoCalcForm(parent)
{
    osagoData = d;
}
osagoCalcForm::~osagoCalcForm()
{
    delete ui;
}
QStringListModel* osagoCalcForm::getHrn(const QString &name)
{

}
void osagoCalcForm::setComboBoxModel(const QString &tableName, QComboBox *cb, int column)
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database("calc.db"));
    model->setTable(tableName);
    model->select();
    cb->setModel(model);
    cb->setModelColumn(column);
    cb->view()->setCurrentIndex(model->index(0, column));
}
void osagoCalcForm::createCompleter()
{
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery("SELECT region_id, "
                    "(SELECT hrn FROM regions AS r WHERE r.coeff = t.region_id) ||  ', ' || hrn ,"
                    "coeff, trailer_coeff  FROM towns AS t",
                    QSqlDatabase::database(dataBase::dbase.connectionName()));
    QCompleter* completer = new QCompleter(this);
    completer->setCompletionColumn(1);
    ui->townLineEdit->setCompleter(completer);
    QCompleter *comp=ui->townLineEdit->completer();
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    QSortFilterProxyModel *filterModel=new QSortFilterProxyModel(comp);
    filterModel->setSourceModel(model);
    filterModel->setFilterKeyColumn(1);
    filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    comp->setModel(filterModel);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    QObject::connect(ui->townLineEdit, SIGNAL(textEdited(QString)), filterModel, SLOT(setFilterRegExp(QString)));

    connect(completer, SIGNAL(activated(QModelIndex)), this, SLOT(calculate()));
}
void osagoCalcForm::activateComboBoxes()
{
    QList<QComboBox*> cbs = findChildren<QComboBox*>();
    foreach (QComboBox* cb, cbs) {
        setComboBoxModel(cb->property("tableName").toString(), cb, cb->modelColumn());
        connect(cb, SIGNAL(activated(int)), this, SLOT(calculate()));
    }
}
void osagoCalcForm::showFields(int num)
{
    ui->powerComboBox->setVisible(num < 2);
    ui->powerLabel->setVisible(num < 2);
    bool isTrack = num==3 || num==6 || num==13;
    ui->clientTypeComboBox->setVisible(!isTrack );
    ui->clientTypeLabel->setVisible(!isTrack);
    ui->classComboBox->setVisible(!isTrack);
    ui->classLabel->setVisible(!isTrack);
    ui->agesComboBox->setVisible(!isTrack);
    ui->agesLabel->setVisible(!isTrack);
    this->adjustSize();
}
void osagoCalcForm::showPeriods(int num)
{
    bool internal = num==0;
    bool foreign = num==2 || num==3;
    ui->internalComboBox->setVisible(internal);
    ui->internalLabel->setVisible(internal);
    ui->foreignComboBox->setVisible(foreign);
    ui->foreignLabel->setVisible(foreign);
}

void osagoCalcForm::calculate()
{
      QString t = ui->townLineEdit->text();
      QList<QComboBox*> cbs = findChildren<QComboBox*>();
      QMap<QString,QModelIndex> data;
      foreach (QComboBox* cb, cbs) {
          data[cb->property("tableName").toString()] = cb->view()->selectionModel()->currentIndex();
      }
      data[ui->townLineEdit->property("tableName").toString()] = getTownIndex();//ui->townLineEdit->completer()->currentIndex();
      if( t.compare("") == 0 ) return;
      ui->bonus->setText(QString::number(CalculatorOsago::calculate(&data), 'f', 2));
     osagoData->coeffs = CalculatorOsago::coeffs;
}
QModelIndex osagoCalcForm::getTownIndex()
{
    int i = ui->townLineEdit->completer()->model()->rowCount();
    QAbstractItemModel* m = ui->townLineEdit->completer()->model();
    for(int row=0; row<m->rowCount(); ++row)
    {
        QString model = m->index(row, 1).data().toString();
        QString entModel = ui->townLineEdit->text();
        if(model == entModel)
        {
            return m->index(row,1);
        }
    }
}

void osagoCalcForm::on_pushButton_clicked()
{

}
