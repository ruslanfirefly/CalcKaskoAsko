#ifndef CASCOTSINFODIALOG_H
#define CASCOTSINFODIALOG_H

#include <QDialog>
#include "dataObjects.h"
namespace Ui {
class CascoTsInfoDialog;
}

class CascoTsInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CascoTsInfoDialog(QWidget *parent = 0);
    ~CascoTsInfoDialog();
    CascoTsInfoDialog(OsagoData* d, QWidget *parent = 0);
signals:
    void prev(int);
    void next(int);
private slots:
    void fillFields();
    void fillData();
private:
    Ui::CascoTsInfoDialog *ui;
    OsagoData* data;
};

#endif // CASCOTSINFODIALOG_H
