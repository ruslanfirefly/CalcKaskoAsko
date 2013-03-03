#ifndef DATAOBJECTS_H
#define DATAOBJECTS_H
#include <QString>
#include <QDate>
#include <QList>
#include <QPair>

struct Addr
{

    QString index, country, state, city, street, house, corp, flat;
};
struct Driver
{
    enum DriverTypes { Owner, Insurancer };
    QString fio;
    QString inn = 0;
    QString documentType;
    QString ser , number;
    Addr addr;
    QString phone;
    bool fizik=true;
    QDate birthday;
};
struct DriverInfo
{
    enum Sexes { Male, Female };
    QString fio;
    QDate birthday;
    Sexes sex = Male;
    QString driverLicence;
    QString stage;
    int dClass;
    int countOfIncidents=0;
};

struct ts
{
    enum PowerTypes { kWt, hp };
    enum TsCategories { A, B, C, D, E };
    enum UsingType { Personal, Learning, Taxi, Special, Other };
    enum DocumentTypes { PTS, STS, TP, PSM };
    QString model, vin, shassi, track, serial, number, date;
    int power=0, passengersCount=8, year=2000, mass=3500, countOfIncidents=0;
    PowerTypes pType=hp;
    TsCategories tCat=B;
    QDate documentDate;
    UsingType uType = Personal;
    int classOwner = 0;
    bool isRental = false;
    DocumentTypes documentType = PTS;
    QString gosNumber;
};
struct OsagoCoeffs
{
    qreal tb;
    qreal kt;
    qreal kbm;
    qreal kvs;
    qreal ko;
    qreal km;
    qreal ks;
    qreal kp;
    qreal sum;
};

struct OsagoData
{
    enum DriversCount { UnlimitedDrivers, LimitDrivers };
    Driver insurancer, owner;
    ts transport;
    bool insurancerIsOwner;
    DriversCount dCount = LimitDrivers;
    QList<DriverInfo> drivers = QList<DriverInfo>();
    QList<QPair<QDate, QDate> > usingPeriods;
    bool hasLastOsago = false;
    QString lastOsagoSerial, lastOsagoNum, lastOsagoCompany, otherInfo, notes, polisSerial, polisNum;
    QDate from, to;
    QString agent;
    OsagoCoeffs coeffs;
};

#endif // DATAOBJECTS_H
