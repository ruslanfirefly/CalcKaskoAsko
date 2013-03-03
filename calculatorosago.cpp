#include "calculatorosago.h"
#include <algorithm>
const QList<int> CalculatorOsago::ignore_power_auto_types = { 2, 4, 5, 7, 8, 9, 10, 11, 12 };
const QList<int> CalculatorOsago::trailers_auto_types = { 6, 13, 3};
OsagoCoeffs CalculatorOsago::coeffs;
CalculatorOsago::CalculatorOsago(QObject *parent) :
    QObject(parent)
{
}
qreal CalculatorOsago::calculate(QMap<QString,QModelIndex> *data)
{

    //qreal kt = (*data)["towns"].model()->itemData((*data)["towns"])[2].toReal();
    qreal tb = getData((*data)["auto_types"],0).toReal();
    qreal kt = getData((*data)["towns"],2).toReal();
    qreal kbm = getData((*data)["classes"],0).toReal();
    qreal kvs = getData((*data)["ages"],0).toReal();
    qreal ko = getData((*data)["client_type"],0).toReal();
    qreal km = getData((*data)["power"],0).toReal();
    qreal kp = 1;
    qreal ks = getData((*data)["internal_period"],0).toReal();
    int auto_types_id = getData((*data)["auto_types"], 2).toInt()-1;
    int client_type_id = getData((*data)["client_type"], 2).toInt()-1;
    int reg_type_id = getData((*data)["reg_type"], 0).toInt();
    if( std::find(ignore_power_auto_types.begin(), ignore_power_auto_types.end(),
                  auto_types_id) != ignore_power_auto_types.end() )
    {
        km = 1;
    }
    if( std::find(trailers_auto_types.begin(), trailers_auto_types.end(), auto_types_id) != trailers_auto_types.end())
    {
       kt = getData((*data)["towns"],3).toReal();
       ko = 1;
       kbm = 1;
       kvs = 1;
       km = 1;
    }
    if(client_type_id == 1)
    {
        kvs = 1;
    }
    if(client_type_id == 1 && auto_types_id == 0)
    {
         tb = getData((*data)["auto_types"],3).toReal();
         kvs = 1;
    }
    if(reg_type_id == 1)
    {
        kbm = 1;
        kt = 1;
        ks = 0.2;
    }
    if(reg_type_id == 2 || reg_type_id == 3)
    {
        kt = 1.7;
        kbm = 1;
        ks = 1;
        kp = getData((*data)["foreign_period"],0).toReal();
    }
    if((reg_type_id == 2 || reg_type_id == 3) && client_type_id == 1)
    {
        kvs = 1.8;
        ko = 1;
    }
    if((reg_type_id == 2 || reg_type_id == 3) && client_type_id == 0)
    {
        kvs = 1.7;
    }
    coeffs.tb = tb;
    coeffs.kt = kt;
    coeffs.kbm = kbm;
    coeffs.kvs = kvs;
    coeffs.ko = ko;
    coeffs.km = km;
    coeffs.ks = ks;
    coeffs.kp = kp;
    coeffs.sum = tb*kt*kbm*kvs*ko*km*ks*kp;
    return coeffs.sum;
}
QVariant CalculatorOsago::getData(QModelIndex index, int column)
{
    return index.model()->data(index.model()->index(index.row(),column));
}
