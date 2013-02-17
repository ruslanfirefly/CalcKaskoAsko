#ifndef OSAGOCALCFORM_H
#define OSAGOCALCFORM_H

#include <QDialog>
#include "database.h"
#include <QStringListModel>
#include <QComboBox>
namespace Ui {
class osagoCalcForm;
}

class osagoCalcForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit osagoCalcForm(QWidget *parent = 0);
    osagoCalcForm(dataBase * base, QWidget *parent);
    ~osagoCalcForm();

private:
Ui::osagoCalcForm *ui;
    dataBase * db;
    QStringListModel* getHrn(const QString& name);
    void setComboBoxModel(const QString& tableName, QComboBox* cb, int column = 0);
    void createCompleter();
    void activateComboBoxes();
private slots:
    void calculate();
    void on_pushButton_clicked();
signals:
    void next();
};

#endif // OSAGOCALCFORM_H
