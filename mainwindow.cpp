#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custom_exceptions.h"
#include "agentsdialog.h"
#include "databaseeditor.h"
#include <QAction>
#include "osagocalcform.h"
#include "osagomaster.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*db = new dataBase("agents.db");
    db->connectDB();
    db->initAgentsDb();
    db = new dataBase("calc.db");
    db->connectDB();
    db->initDb();*/
    db = new dataBase();
    db->connectDB();
    db->initDb();



#ifdef BUILD_WITH_EDITOR
    QAction* dbeditor = new QAction( tr("&Open db editor"), this);
    dbeditor->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    connect(dbeditor, SIGNAL(triggered()), this, SLOT(openDbEditor()));
    ui->menu->addAction(dbeditor);
#endif
}
void MainWindow::openDbEditor()
{
    QDialog* ad = new dataBaseEditor(db, this);
    ad->setModal(true);
    ad->show();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_action_triggered()
{
    QDialog* ad = new agentsDialog(db);
    ad->setModal(true);
    ad->show();
}

void MainWindow::on_pushButton_clicked()
{
    //QDialog* ad = new osagoCalcForm(db, this);
    //ad->setModal(true);
    //ad->show();
    OsagoMaster* m = new OsagoMaster(this);
}
