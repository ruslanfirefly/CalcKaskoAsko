#ifndef DATAOBJECTS_H
#define DATAOBJECTS_H
#include <QString>
#include <QDate>
struct Addr
{

    QString index, country, state, city, street, house, corp, flat;
};
struct Driver
{
    enum DriverTypes { Owner, Insurancer };
    QString fio;
    qlonglong inn = 0;
    QString documentType;
    QString ser , number;
    Addr addr;
    QString phone;    
};
struct ts
{
    enum PowerTypes { kWt, hp };
    enum TsCategories { A, B, C, D, E };
    enum UsingType { Personal, Learning, Taxi, Special, Other };
    QString model, vin, shassi, track, serial, number, date;
    int power, passengersCount, year, mass, countOfIncidents;
    PowerTypes pType;
    TsCategories tCat;
    QDate documentDate;
    UsingType uType;
    int classOwner;
    bool isRental;
};

struct OsagoData
{
    Driver insurancer, owner;
    ts transport;
    bool insurancerIsOwner;
};

#endif // DATAOBJECTS_H
