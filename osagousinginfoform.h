#ifndef OSAGOUSINGINFOFORM_H
#define OSAGOUSINGINFOFORM_H

#include <QDialog>
#include <QGridLayout>
namespace Ui {
class OsagoUsingInfoForm;
}

class OsagoUsingInfoForm : public QDialog
{
    Q_OBJECT
    const int maxDrivers = 4, maxDateIntervals = 4;
    int currentDrivers, currentDateIntervals;
public:
    explicit OsagoUsingInfoForm(QWidget *parent = 0);
    ~OsagoUsingInfoForm();
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

signals:
    void prev();
    void printRequest();

    void printBlank();
private:
    Ui::OsagoUsingInfoForm *ui;
};

#endif // OSAGOUSINGINFOFORM_H
