#ifndef OSAGOMASTER_H
#define OSAGOMASTER_H

#include <QObject>
#include <QStateMachine>
#include <QDialog>
#include "osagocalcform.h"
#include "dataObjects.h"
#include <QtWebKit/QWebFrame>
class OsagoMaster : public QObject
{
    Q_OBJECT
    int currentStep = 0;
    QList<QDialog*> dialogs;
    OsagoData data;
public:
    explicit OsagoMaster(QObject *parent = 0);
    static const QVector<QString> categories;
    static const QVector<const char*> usingTypes;
    static const QVector<const char*> sexes;
signals:
    
public slots:
    void next();
    void next(int);
    void prev();
    void prev(int);
    void step(int);
    void printRequest();
    void printRequestPreview();
    void printBlankPreview();
    void printBlank();

private:
    QString createLastOsagoInfo(OsagoData* data);
    QString createUsingInfo(const QPair<QDate, QDate> *usingPeriods);
    QString getClass(int num);
    void fillTextField(const QString& id, const QString& text, QWebFrame* frame);
    void fillDriverData(const QString& prefix, Driver* driver, QWebFrame* frame);
    void fillDriverInfoTable(QList<DriverInfo> info, QWebFrame* frame);
};

#endif // OSAGOMASTER_H
