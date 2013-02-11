#ifndef CALCULATOROSAGO_H
#define CALCULATOROSAGO_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QModelIndex>
class CalculatorOsago : public QObject
{
    Q_OBJECT
    static QVariant getData(QModelIndex index, int column);
public:
    explicit CalculatorOsago(QObject *parent = 0);
    static qreal calculate(QMap<QString,QModelIndex>  * data);
    static const QList<int> ignore_power_auto_types;
    static const QList<int> trailers_auto_types;
signals:
    
public slots:
    
};

#endif // CALCULATOROSAGO_H
