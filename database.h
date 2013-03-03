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

public:
    explicit dataBase(QObject *parent = 0);
    dataBase(const QString& name, QObject *parent = 0);
    ~dataBase();
    static QSqlDatabase dbase;
    static QSqlDatabase agentsDb;
signals:
    
public slots:
    void connectDB();

    std::shared_ptr<QSqlQuery> query(const QString& q);
    std::shared_ptr<QSqlQuery> query(const QString& q, const QString& dbName);
    void initDb();
    void initAgentsDb();
    void fillFromJson(const QString& path);

private:
    static const QList<QString> tablesDescriptions;
    static const QList<QString> agentsTablesDescriptions;
};

#endif // DATABASE_H
