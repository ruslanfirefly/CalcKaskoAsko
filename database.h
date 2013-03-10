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
#include <QSqlTableModel>
class dataBase : public QObject
{
    Q_OBJECT

public:
    explicit dataBase(QObject *parent = 0);
    dataBase(const QString& name, QObject *parent = 0);
    ~dataBase();
    static QSqlDatabase dbase;
    static QSqlDatabase agentsDb;
    static QSqlDatabase cascoDb;
    static QList<QStringList> parseCSVFile(const QString& name);
    static QStringList parseCSVString(QString &string);
signals:
    
public slots:
    void connectDB();

    static std::shared_ptr<QSqlQuery> query(const QString& q);
    static std::shared_ptr<QSqlQuery> query(const QString& q, const QString& dbName);
    void initDb();
    void initAgentsDb();
    void initCascoDb();
    void fillFromJson(const QString& path);


private:
    static const QList<QString> tablesDescriptions;
    static const QList<QString> agentsTablesDescriptions;
    static const QList<QString> cascoTableDescriptions;
    void fillCascoData(const QList<QStringList>& data);
    void fillCascoMarks(const QList<QStringList>& data);
    void fillCascoModels(const QList<QStringList>& datas);
    void fillCascoDops(const QList<QStringList>& datas);
    void bindDopsToModel(const QList<QStringList>& datas);
    bool checkDopsString(const QString& dops, const QString &dop);
};

#endif // DATABASE_H
