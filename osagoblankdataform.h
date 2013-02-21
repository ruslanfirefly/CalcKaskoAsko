#ifndef OSAGOBLANKDATAFORM_H
#define OSAGOBLANKDATAFORM_H

#include <QDialog>
#include "dataObjects.h"
namespace Ui {
class OsagoBlankDataForm;
}

class OsagoBlankDataForm : public QDialog
{
    Q_OBJECT
    Driver* data = nullptr;
    bool* isOwner = nullptr;
    Driver::DriverTypes driverType;
public:
    explicit OsagoBlankDataForm(QWidget *parent = 0);
    OsagoBlankDataForm( Driver* d,  Driver::DriverTypes dType, bool* insurancerIsOwner = false, QWidget *parent = 0);
    ~OsagoBlankDataForm();
private slots:
    void fillFields();
    void hideFields(Driver::DriverTypes dType);
    void fillData();
    void sendNext();
private:
    Ui::OsagoBlankDataForm *ui;
signals:
    void next();
    void prev();
    void next(int);
};

#endif // OSAGOBLANKDATAFORM_H
