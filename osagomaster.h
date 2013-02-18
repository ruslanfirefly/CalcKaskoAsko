#ifndef OSAGOMASTER_H
#define OSAGOMASTER_H

#include <QObject>
#include <QStateMachine>
#include <QDialog>
#include "osagocalcform.h"
#include "dataObjects.h"
class OsagoMaster : public QObject
{
    Q_OBJECT
    int currentStep = 0;
    QList<QDialog*> dialogs;
    OsagoData data;
public:
    explicit OsagoMaster(QObject *parent = 0);
    
signals:
    
public slots:
    void next();
    void next(int);
    void prev();
    void prev(int);
    void step(int);
    void printRequest();
    void printRequestPreview();
    void printBlank();
    
};

#endif // OSAGOMASTER_H
