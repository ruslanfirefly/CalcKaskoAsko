#ifndef CASCODATADIALOG_H
#define CASCODATADIALOG_H

#include <QDialog>
#include "dataObjects.h"
namespace Ui {
class CascoDataDialog;
}

class CascoDataDialog : public QDialog
{
    Q_OBJECT    
public:
    enum CascoDialogType { Insurancer, Owner, Profiter };
    explicit CascoDataDialog(QWidget *parent = 0);    
    ~CascoDataDialog();
    CascoDataDialog(CascoDialogType t, OsagoData* d,QWidget *parent = 0);
signals:
    void next(int);
    void prev(int);
private:
    CascoDialogType dType;
    Ui::CascoDataDialog *ui;
    OsagoData* data;
    Driver* driver;
protected:
    void showEvent(QShowEvent *);
private slots:
    void fillData();
    void fillFields();
    void hideAndNext();
    void clientTypeChanged(int state);
};

#endif // CASCODATADIALOG_H
