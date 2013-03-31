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
protected:
    void showEvent(QShowEvent *);
signals:
    void prev(int);
    void printBlank();
private slots:
    void fillData();
private:
    Ui::CascoSummaryDialog *ui;
    OsagoData* data;
    void setElementsState(bool state, QWidgetList elements);
};

#endif // CASCOSUMMARYDIALOG_H
