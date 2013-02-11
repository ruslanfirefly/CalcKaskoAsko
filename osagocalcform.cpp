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
osagoCalcForm::osagoCalcForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::osagoCalcForm)
{
    ui->setupUi(this);
}
osagoCalcForm::osagoCalcForm(dataBase *base, QWidget *parent) : osagoCalcForm(parent)
{
    db = base;
    activateComboBoxes();
    createCompleter();
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
    QSqlTableModel* model = new QSqlTableModel;
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
                    "coeff, trailer_coeff  FROM towns AS t");    
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
    //connect(ui->townLineEdit, SIGNAL(textChanged(QString)), this, SLOT(calculate()));
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
void osagoCalcForm::calculate()
{
      QString t = ui->townLineEdit->text();
      QList<QComboBox*> cbs = findChildren<QComboBox*>();
      QMap<QString,QModelIndex> data;
      foreach (QComboBox* cb, cbs) {
          data[cb->property("tableName").toString()] = cb->view()->selectionModel()->currentIndex();
      }
      data[ui->townLineEdit->property("tableName").toString()] = ui->townLineEdit->completer()->currentIndex();
      if( t.compare("") == 0 ) return;
      ui->bonus->setText(QString::number(CalculatorOsago::calculate(&data), 'f', 2));
}

void osagoCalcForm::on_pushButton_clicked()
{
    QFile f(":/templates/osago_zayavlenie.html");
    f.open(QIODevice::ReadOnly);
    Printer::getInstance().printPreview(QString::fromUtf8(f.readAll()));
}
