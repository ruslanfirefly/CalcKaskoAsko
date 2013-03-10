#ifndef OSAGOCALCFORM_H
#define OSAGOCALCFORM_H

#include <QDialog>
#include "database.h"
#include <QStringListModel>
#include <QComboBox>
#include "dataObjects.h"
namespace Ui {
class osagoCalcForm;
}

class osagoCalcForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit osagoCalcForm(QWidget *parent = 0);
    osagoCalcForm(OsagoData *d, QWidget *parent = 0);
    ~osagoCalcForm();

private:
Ui::osagoCalcForm *ui;
    OsagoData* osagoData;
    QStringListModel* getHrn(const QString& name);
    void setComboBoxModel(const QString& tableName, QComboBox* cb, int column = 0);
    void createCompleter();
    void activateComboBoxes();
    QModelIndex getTownIndex();
private slots:
    void calculate();
    void on_pushButton_clicked();
    void showFields(int num);
    void showPeriods(int num);
signals:
    void next();
};

#endif // OSAGOCALCFORM_H
