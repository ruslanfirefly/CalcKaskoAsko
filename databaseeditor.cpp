#include "databaseeditor.h"
#include "ui_databaseeditor.h"
#include <QSqlDatabase>
#include <QStringListModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QMessageBox>
#include "custom_exceptions.h"
#include "database.h"
dataBaseEditor::dataBaseEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataBaseEditor)
{
    ui->setupUi(this);
    ui->tablesNames->setModel(new QStringListModel(getTables()));
    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    connect(ui->tablesNames, SIGNAL(activated(QString)), this, SLOT(changeModel(QString)));
}
dataBaseEditor::dataBaseEditor(dataBase *d, QWidget *parent) : dataBaseEditor(parent)
{
    db = d;
    QAction* dbeditor = new QAction( tr("&Load from json"), this);
    dbeditor->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_J));
    connect(dbeditor, SIGNAL(triggered()), this, SLOT(loadFromJSON()));
    this->addAction(dbeditor);
}

dataBaseEditor::~dataBaseEditor()
{
    delete ui;
}
QList<QString> dataBaseEditor::getTables()
{
    QList<QString> tables;
    QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name",
                    QSqlDatabase::database(dataBase::dbase.connectionName()));
    while (query.next()) {
        QString table = query.value(0).toString();
        tables.push_back(table);
    }
    return tables;
}
void dataBaseEditor::changeModel(QString name)
{
    ui->tableView->model()->deleteLater();
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database(dataBase::dbase.connectionName()));
    model->setTable(name);
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->tableView->setModel(model);
    return;
}
void dataBaseEditor::loadFromJSON()
{
    try
    {
        QString file = QFileDialog::getOpenFileName(this,tr("Choose file"), "", tr("JSON files (*.json)"));
        db->fillFromJson(file);
    }
    catch(SqlException& exc)
    {
        QMessageBox::critical(this, tr("Error"), tr("Sql error: ")+tr(exc.what())+tr("\nQuery text: ")+exc.text());
    }
    catch(std::exception& exc)
    {

        QMessageBox::critical(this, tr("Error"), tr("Error load database ")+tr(exc.what()));
    }
}
