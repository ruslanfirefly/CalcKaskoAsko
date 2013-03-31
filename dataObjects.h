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
struct risk
{
    enum RisksNums { RiskCasco, RiskLife };
    risk(const QString& p) : htmlClassPrefix(p) {}
    bool enabled = false;
    qreal sum=0, tarif=0;
    QString prem = "";
    QString htmlClassPrefix= "";
};

struct Driver
{
    enum DriverTypes { Owner, Insurancer };
    QString fio;
    QString inn = 0;
    QString documentType;
    QString ser, number, documentCustomer;
    QDate documentDate;
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
struct AdditionalEquipment
{
    QString name, model;
    int count;
    qreal cost, prem;
};

struct ts
{
    enum PowerTypes { kWt, hp };
    enum TsCategories { A, B, C, D, E };
    enum UsingType { Personal, Learning, Taxi, Special, Other };
    enum DocumentTypes { PTS, STS, TP, PSM };
    QString model="", vin="", shassi="", track="", serial="", number="", date="";
    int power=0, passengersCount=8, year=2000, mass=3500, countOfIncidents=0;
    PowerTypes pType=hp;
    TsCategories tCat=B;
    QDate documentDate;
    UsingType uType = Personal;
    int classOwner = 0;
    bool isRental = false;
    DocumentTypes documentType = PTS;
    QString gosNumber="";
    QString color="";
    QString engineNum="";
    int mileage;
    QString ptsData, stsData;
};
struct CascoData
{
    qreal sum = 0;
    qreal tarif = 0, prem=0;
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
    enum LifeInsType { NoLifeIns, LifeInsBySeatsCount, LifeInsFull};
    enum CalculatesType { CalculateBySto, CalculateByIndependetRater, CalculateByInsurer };
    Driver insurancer, owner, profiter;
    ts transport;
    bool insurancerIsOwner = false, insurancerIsProfiter = false;
    DriversCount dCount = LimitDrivers;
    QList<DriverInfo> drivers = QList<DriverInfo>();
    QList<AdditionalEquipment> dops = QList<AdditionalEquipment>();
    QList<QPair<QDate, QDate> > usingPeriods;
    bool hasLastOsago = false;
    QString lastOsagoSerial, lastOsagoNum, lastOsagoCompany, otherInfo, notes, polisSerial, polisNum;
    QDate from, to;
    QString agent;
    OsagoCoeffs coeffs;
    CascoData cascoData;
    LifeInsType lifeIns=NoLifeIns;
    bool withAmortisation=false;
    int seatsCount=0;
    CalculatesType calculateType = CalculateBySto;
    bool hasDop, singlePayment, cashPayment, hasDamadge;
    qreal cashSum;
    QString damadgeDesription;
    QString paymentDoc;
    QString agentNumber, agentDate;
    QDateTime startDate;
    QTime lookTime;
    QList<risk> risks = {
        risk("casco")
        ,risk("life")
    };

};

#endif // DATAOBJECTS_H
