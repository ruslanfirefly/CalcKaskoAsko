#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <exception>
#include <stdexcept>
#include <memory>
#include <bits/shared_ptr.h>
#include <algorithm>
#include <QSqlError>
class dataBase : public QObject
{
    Q_OBJECT
    QSqlDatabase dbase;
public:
    explicit dataBase(QObject *parent = 0);
    dataBase(const QString& name, QObject *parent = 0);
    ~dataBase();
signals:
    
public slots:
    void connectDB();
    std::shared_ptr<QSqlQuery> query(const QString& q);
    void initDb();
    void fillFromJson(const QString& path);
private:
    static const QList<QString> tablesDescriptions;
};

#endif // DATABASE_H
