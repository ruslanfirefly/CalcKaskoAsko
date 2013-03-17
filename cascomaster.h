#ifndef CASCOMASTER_H
#define CASCOMASTER_H

#include <QObject>
#include <QDialog>
#include <QList>
#include <dataObjects.h>
#include <QMutex>
class CascoMaster : public QObject
{
    Q_OBJECT
    QList<QDialog*> forms;
    void step(int);
    int currentStep = 0;
    OsagoData data;
    QMutex m;
    void fillForms(std::initializer_list<QDialog *> f);
public:
    explicit CascoMaster(QObject *parent = 0);
    
signals:
    
public slots:
    void next();
    void prev();
    void next(int);
    void prev(int);
    void hideCurrentForm();
    void showCurrentForm();
};

#endif // CASCOMASTER_H
