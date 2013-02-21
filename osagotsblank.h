#ifndef OSAGOTSBLANK_H
#define OSAGOTSBLANK_H

#include <QDialog>
#include "dataObjects.h"
namespace Ui {
class OsagoTsBlank;
}

class OsagoTsBlank : public QDialog
{
    Q_OBJECT
    bool *isOwner;
public:
    explicit OsagoTsBlank(QWidget *parent = 0);
    OsagoTsBlank(ts* d, bool* insurancerIsOwner, QWidget *parent = 0);
    ~OsagoTsBlank();
    
private:
    Ui::OsagoTsBlank *ui;
    ts* data;
private slots:
    void sendPrev();
    void fillFields();
    //void on_passengersCount_activated(int index);

    void on_tsTypeComboBox_activated(int index);

signals:
    void next();
    void prev();
    void prev(int);
};

#endif // OSAGOTSBLANK_H
