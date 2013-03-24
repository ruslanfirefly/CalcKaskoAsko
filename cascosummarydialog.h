#ifndef CASCOSUMMARYDIALOG_H
#define CASCOSUMMARYDIALOG_H

#include <QDialog>
#include "dataObjects.h"
namespace Ui {
class CascoSummaryDialog;
}

class CascoSummaryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CascoSummaryDialog(QWidget *parent = 0);
    ~CascoSummaryDialog();
    CascoSummaryDialog(OsagoData* data, QWidget *parent=0);
    
signals:
    void prev(int);
private:
    Ui::CascoSummaryDialog *ui;
    OsagoData* data;
};

#endif // CASCOSUMMARYDIALOG_H
