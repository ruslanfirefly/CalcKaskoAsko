#ifndef DATAOBJECTS_H
#define DATAOBJECTS_H
#include <QString>

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
struct OsagoData
{
    Driver insurancer, owner;
    bool insurancerIsOwner;
};

#endif // DATAOBJECTS_H
