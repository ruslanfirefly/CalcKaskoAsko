#ifndef OSAGOTSBLANK_H
#define OSAGOTSBLANK_H

#include <QDialog>

namespace Ui {
class OsagoTsBlank;
}

class OsagoTsBlank : public QDialog
{
    Q_OBJECT
    bool *isOwner;
public:
    explicit OsagoTsBlank(QWidget *parent = 0);
    OsagoTsBlank(bool* insurancerIsOwner, QWidget *parent = 0);
    ~OsagoTsBlank();
    
private:
    Ui::OsagoTsBlank *ui;
private slots:
    void sendPrev();
signals:
    void next();
    void prev();
    void prev(int);
};

#endif // OSAGOTSBLANK_H
