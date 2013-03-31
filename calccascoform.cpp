#include "calccascoform.h"
#include "ui_calccascoform.h"
#include <QSqlQueryModel>
#include "database.h"
#include <QCompleter>
#include <QSortFilterProxyModel>
#include <QSqlRecord>
#include <memory.h>
calcCascoForm::calcCascoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calcCascoForm)
{
    ui->setupUi(this);
    ui->dopInfo->hide();
    ui->dopInfo->setWordWrap(true);
    createModelField();
    activateComboBoxes();
    connect(ui->premSpinBox, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect(ui->nextButton, &QPushButton::clicked, [this](){ if(data->cascoData.prem != 0) emit this->next(1);} );
}
calcCascoForm::calcCascoForm(OsagoData *d, QWidget *parent) : calcCascoForm(parent)
{
    data = d;
}

void calcCascoForm::createModelField()
{
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery("SELECT mark || ' ' || name, coeff, id FROM auto_models",
                    QSqlDatabase::database(dataBase::cascoDb.connectionName()));
    QCompleter* completer = new QCompleter(this);
    completer->setCompletionColumn(0);
    ui->modelLineEdit->setCompleter(completer);
    QCompleter *comp=ui->modelLineEdit->completer();
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    QSortFilterProxyModel *filterModel=new QSortFilterProxyModel(comp);
    sortModel = filterModel;
    filterModel->setSourceModel(model);
    filterModel->setFilterKeyColumn(0);
    filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    comp->setModel(filterModel);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);

    QObject::connect(ui->modelLineEdit, SIGNAL(textEdited(QString)), filterModel, SLOT(setFilterRegExp(QString)));
    connect(comp, SIGNAL(activated(QModelIndex)), this, SLOT(changeCarModel(QModelIndex)));
    connect(comp, SIGNAL(activated(QModelIndex)), this, SLOT(calculate()));
}
void calcCascoForm::changeCarModel(QModelIndex index)
{
    auto id = index.model()->index(index.row(),2).data().toInt();
    //QSqlQuery q(QString("SELECT * from autos_dops WHERE auto=%1").arg(id), dataBase::cascoDb);
    //q.exec()
    QString queryText(QString("SELECT * from autos_dops WHERE auto=%1").arg(id));
    QSqlQueryModel* m = new QSqlQueryModel(this);
    m->setQuery(queryText, QSqlDatabase::database(dataBase::cascoDb.connectionName()));

    if(m->rowCount()>0)
    {
        ui->dopInfo->show();
        QString dopText(QString("Внимание! Для страхования данного автомобиля "
                "необходима установка следующего доп. оборудования:\n"));
        for(int row = 0; row<m->rowCount(); ++row)
        {
            dopText += QString("Вариант %1: %2\n")
                    .arg(QString::number(row+1))
                    .arg(m->index(row,1).data().toString());
        }
        ui->dopInfo->setText(dopText);
        this->adjustSize();
    }
    else
    {
        ui->dopInfo->hide();
    }
}

void calcCascoForm::activateComboBoxes()
{
    QList<QComboBox*> cbs = findChildren<QComboBox*>();
    foreach (QComboBox* cb, cbs) {
        setComboBoxModel(cb->property("tableName").toString(), cb, cb->modelColumn());
        connect(cb, SIGNAL(activated(int)), this, SLOT(calculate()));
    }
}
void calcCascoForm::setComboBoxModel(const QString &tableName, QComboBox *cb, int column)
{
    QSqlTableModel* model = new QSqlTableModel(this, dataBase::cascoDb);

    model->setTable(tableName);
    model->select();
    cb->setModel(model);
    cb->setModelColumn(column);
    cb->view()->setCurrentIndex(model->index(0, column));
}
calcCascoForm::~calcCascoForm()
{
    delete ui;
}
void calcCascoForm::calculate()
{
    if(ui->modelLineEdit->text() == "") return;
    qreal modelCoeff = getCoefFromModelLineEDit();
    //qreal modelCoeff = getCoefFromIndex(ui->modelLineEdit->completer()->currentIndex());
    qreal yearCoeff = getCoefFromIndex(ui->yearComboBox->view()->selectionModel()->currentIndex());
    qreal agesCoeff = getCoefFromIndex(ui->agesComboBox->view()->selectionModel()->currentIndex());
    qreal transCoeff = getCoefFromIndex(ui->transComboBox->view()->selectionModel()->currentIndex());
    qreal tarif = (modelCoeff + yearCoeff)*agesCoeff*transCoeff;
    ui->tarif->setText(QString("(%1 + %3) * %2 * %4 = %5")
                       .arg(modelCoeff)
                       .arg(agesCoeff)
                       .arg(yearCoeff)
                       .arg(transCoeff)
                       .arg(tarif)
                       );
    data->cascoData.prem = tarif*ui->premSpinBox->value()/100;
    data->cascoData.tarif = tarif;
    ui->prem->setText(QString::number(data->cascoData.prem, 'f', 3) + tr(" тыс. руб"));
    data->transport.model = ui->modelLineEdit->text();
    data->cascoData.sum = ui->premSpinBox->value();
}
qreal calcCascoForm::getCoefFromIndex(QModelIndex index)
{

    const QAbstractItemModel* m = index.model();
    if(const QSqlTableModel* sm = qobject_cast<const QSqlTableModel*>(m))
    {
        auto data = sm->record(index.row()).value("coeff");
        return sm->record(index.row()).value("coeff").toReal();
    }
    else
    {
        return m->index(index.row(),1).data().toString().replace(',','.').toDouble();
    }
}
qreal calcCascoForm::getCoefFromModelLineEDit()
{
    int i = ui->modelLineEdit->completer()->model()->rowCount();
    QAbstractItemModel* m = ui->modelLineEdit->completer()->model();
    for(int row=0; row<m->rowCount(); ++row)
    {
        QString model = m->index(row, 0).data().toString();
        QString entModel = ui->modelLineEdit->text();
        if(model == entModel)
        {
            return m->index(row, 1).data().toString().replace(',','.').toDouble();
        }
    }
    return 0;
}
