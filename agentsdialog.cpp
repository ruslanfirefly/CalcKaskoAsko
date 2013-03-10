#include "agentsdialog.h"
#include "ui_agentsdialog.h"
#include "dateDelegate.h"
#include <QTimer>
#include <QCloseEvent>

agentsDialog::agentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agentsDialog)
{
    ui->setupUi(this);
}
void agentsDialog::closeEvent(QCloseEvent *e)
{
    if(!model->submitAll())
    {
        qDebug()<<"Error "<<model->lastError().text();
        e->ignore();
    }
    else
    {
        e->accept();
    }

}

agentsDialog::agentsDialog(dataBase* base, QWidget *parent) :  agentsDialog(parent)
{
    db = base;
    qDebug()<<db->agentsDb.connectionName();
    bool t = db->agentsDb.open();
    model = std::shared_ptr<QSqlTableModel>(new QSqlTableModel(this, QSqlDatabase::database(db->agentsDb.connectionName())));
    model->setTable("agents");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1,Qt::Horizontal, tr("Second name"));
    model->setHeaderData(0,Qt::Horizontal, tr("First name"));
    model->setHeaderData(2,Qt::Horizontal, tr("Fird name"));
    model->setHeaderData(3,Qt::Horizontal, tr("Contract's number"));
    model->setHeaderData(4,Qt::Horizontal, tr("Contract's date"));
    ui->agentsTable->setModel(model.get());
    ui->agentsTable->setItemDelegateForColumn(4,new DateDelegate(ui->agentsTable));
    //ui->agentsTable->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    connect(ui->agentsTable->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), this, SLOT(adjust()));
    connect(this->ui->addAgentButton, SIGNAL(clicked()), this, SLOT(addAgent()));
    connect(this->ui->delAgentButton, SIGNAL(clicked()), this, SLOT(delAgent()));
}

agentsDialog::~agentsDialog()
{
    delete ui;
}
void agentsDialog::adjust()
{

}
void agentsDialog::addAgent()
{
    if(!ui->agentsTable->model()->insertRow(0));
    {
        qDebug()<<"Error"<<model->database().lastError().text();
        qDebug()<<"Error"<<model->lastError().text();
    }
    ui->agentsTable->setFocus();
    this->ui->agentsTable->edit(this->ui->agentsTable->model()->index(0,0));
}
void agentsDialog::delAgent()
{
    QModelIndexList lst = ui->agentsTable->selectionModel()->selection().indexes();
    qSort(lst.begin(), lst.end(), qGreater<QModelIndex>());
    std::for_each(lst.begin(), lst.end(), [this](const QModelIndex& index)
    {
                  this->ui->agentsTable->model()->removeRow(index.row());
                  this->ui->agentsTable->reset();

    });
    this->ui->agentsTable->edit(this->ui->agentsTable->model()->index(0,0));
}

