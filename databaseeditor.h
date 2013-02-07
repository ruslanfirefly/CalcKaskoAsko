#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QList>
#include <QString>
#include "database.h"
namespace Ui {
class dataBaseEditor;
}

class dataBaseEditor : public QDialog
{
    Q_OBJECT
    
public:
    explicit dataBaseEditor(QWidget *parent = 0);
    dataBaseEditor( dataBase* d,QWidget *parent = 0);
    ~dataBaseEditor();
    
private:
    dataBase* db = nullptr;
    Ui::dataBaseEditor *ui;    
    QList<QString> getTables();
private slots:
    void changeModel(QString);
    void loadFromJSON();
};

#endif // DATABASEEDITOR_H
