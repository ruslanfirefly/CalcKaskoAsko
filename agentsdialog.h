#ifndef AGENTSDIALOG_H
#define AGENTSDIALOG_H

#include <QDialog>
#include "database.h"
#include "QSqlTableModel"
#include <memory>
#include <bits/shared_ptr.h>
namespace Ui {
class agentsDialog;
}

class agentsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit agentsDialog(QWidget *parent = 0);
    agentsDialog(dataBase* base, QWidget *parent = 0);
    ~agentsDialog();
    
private:
    Ui::agentsDialog *ui;
    dataBase* db = nullptr;
    std::shared_ptr<QSqlTableModel> model = std::shared_ptr<QSqlTableModel>(new QSqlTableModel);
public slots:
    void adjust();
    void addAgent();
    void delAgent();
protected:
    virtual void closeEvent(QCloseEvent *);
};

#endif // AGENTSDIALOG_H
