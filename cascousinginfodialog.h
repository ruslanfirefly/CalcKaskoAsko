#ifndef CASCOUSINGINFODIALOG_H
#define CASCOUSINGINFODIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <dataObjects.h>
namespace Ui {
class CascoUsingInfoDialog;
}

class CascoUsingInfoDialog : public QDialog
{
    Q_OBJECT
    const int maxDrivers = 4, maxDateIntervals = 4;
    int currentDrivers, currentDateIntervals;
public:
    explicit CascoUsingInfoDialog(OsagoData* d, QWidget *parent = 0);
    ~CascoUsingInfoDialog();
private slots:
    void hideDriver();
    void showDriver();
    void setDriverVisible(bool, int);
    void setTablwRowItemVisible(bool, int, QGridLayout*);
    void setTablwRowItemEnable(bool, int, QGridLayout*);
    void on_addTimeButton_clicked();
    void on_delTimeButton_clicked();
    void setUnlimDriversEnabled(bool);
    void lastOsagoContractEnable(bool);
    void on_printRequest_clicked();
    void fillFields();
    void fillData();
    void fillComboBoxes();
    void on_compareWithUsing_stateChanged(int arg1);

signals:
    void prev();
    void printRequest();

    void printBlank();
private:
    Ui::CascoUsingInfoDialog *ui;
    OsagoData* data;
};

#endif // CASCOUSINGINFODIALOG_H
