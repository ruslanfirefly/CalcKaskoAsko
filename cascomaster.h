#ifndef CASCOMASTER_H
#define CASCOMASTER_H

#include <QObject>
#include <QDialog>
#include <QList>
#include <dataObjects.h>
#include <QMutex>
#include <QtWebKitWidgets>
class CascoMaster : public QObject
{
    Q_OBJECT
    QList<QDialog*> forms;
    void step(int);
    int currentStep = 0;
    OsagoData data;
    QMutex m;
    void fillForms(std::initializer_list<QDialog *> f);
    void fillBlank(QWebView*);
    void openPrintDialog(QWebView*);
    QString addrToString(const Addr* addres);
    QString getDriverData(const Driver* driver, bool fullData);

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
    void printBlank();

};

#endif // CASCOMASTER_H
