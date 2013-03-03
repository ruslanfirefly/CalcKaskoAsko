#include "database.h"
#include "custom_exceptions.h"
#include "json.h"
#include <QFile>
#include "stdexcept"
#include <QTextCodec>
#include <QApplication>
#include <QProgressBar>
QSqlDatabase dataBase::dbase = QSqlDatabase();
QSqlDatabase dataBase::agentsDb = QSqlDatabase();
const QList<QString> dataBase::tablesDescriptions =
{
    "PRAGMA foreign_keys=ON",

    " CREATE TABLE IF NOT EXISTS auto_types("
    "hrn TEXT,"
    "coeff INTEGER,"
     "id INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT NULL,"
    "coeff_ur INTEGER DEFAULT 0"
    ")",
    " CREATE TABLE IF NOT EXISTS client_type("
    "coeff INTEGER,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS reg_type("
    "coeff INTEGER PRIMARY KEY AUTOINCREMENT,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS regions("
    "coeff INTEGER PRIMARY KEY AUTOINCREMENT,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS towns("
    "id INTEGER,"
    "hrn TEXT,"
    "coeff INTEGER,"
    "trailer_coeff INTEGER,"
    "region_id INTEGER,"
    "FOREIGN KEY (region_id) REFERENCES regions (coeff)"
    ")",
    " CREATE TABLE IF NOT EXISTS classes("
    "coeff INTEGER,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS ages("
     "coeff INTEGER,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS power("
    "coeff INTEGER,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS internal_period("
    "coeff INTEGER,"
    "hrn TEXT"
    ")",
    " CREATE TABLE IF NOT EXISTS foreign_period("
     "coeff INTEGER,"
    "hrn TEXT"
    ")"

};
const QList<QString> dataBase::agentsTablesDescriptions =
{
    "PRAGMA foreign_keys=ON",
    " CREATE TABLE IF NOT EXISTS agents("
    "first_name TEXT,"
    "second_name TEXT,"
    "third_name TEXT,"
    "number TEXT,"
    "date INTEGER,"
    "PRIMARY KEY(number, date)"
    ")"
};
void dataBase::fillFromJson(const QString &path)
{
    QProgressBar bar;
    bar.show();
    QFile file(path);
    if(!file.open(QFile::ReadOnly))
    {
        throw std::runtime_error(("No file "+ path).toStdString());
    }
    bool ok = false;
    QVariantMap map = QtJson::parse(QString::fromUtf8(file.readAll().data()), ok).toMap();
    if(!ok)
    {
        throw std::runtime_error(("Cant parse "+ path).toStdString());
    }
    for(QVariantMap::const_iterator it = map.begin(); it != map.end(); ++it)
    {
        QList<QVariant> list = it.value().toList();
        for(QList<QVariant>::const_iterator list_it = list.begin(); list_it != list.end(); ++list_it)
        {
            bar.setValue(bar.value() >= bar.maximum() ? 0 : bar.value()+1);
            qApp->processEvents();
            QList<QVariant> values = list_it->toList();
            QString q_text = QString("INSERT INTO %1 ( coeff, hrn  ) VALUES ( '%2', '%3' )")
                    .arg(it.key())
                    .arg(values.at(0).toString())
                    .arg(values.at(1).toString());

            query(q_text);
        }
    }
    QList<QVariant> regions = map["regions"].toList();
    for(QList<QVariant>::const_iterator it = regions.begin(); it!= regions.end(); ++it )
    {
        QList<QVariant> towns = it->toList().at(2).toList();
        for(QList<QVariant>::const_iterator town_it = towns.begin(); town_it != towns.end(); ++town_it )
        {
            bar.setValue(bar.value() >= bar.maximum() ? 0 : bar.value()+1);
            qApp->processEvents();
            QList<QVariant> town_desc = town_it->toList();
            QString q_text = QString("INSERT INTO towns VALUES ( %1, '%2', %3, %4, %5)")
                    .arg(town_desc.at(0).toInt())
                    .arg(town_desc.at(1).toString())
                    .arg(town_desc.at(2).toString())
                    .arg(town_desc.at(3).toString())
                    .arg(it->toList().at(0).toInt());
            query(q_text);
        }
    }
    bar.close();
}

void dataBase::initDb()
{

    std::for_each(dataBase::tablesDescriptions.begin(), dataBase::tablesDescriptions.end(),
                  [this](const QString& desc){
        try
        {
            query(desc);
        }
        catch (const SqlException& exc)
        {
            qDebug()<<exc.err().text();
        }
    });
    initAgentsDb();
}
void dataBase::initAgentsDb()
{
    foreach (const QString& desc, agentsTablesDescriptions) {
        try
        {
            query(desc, agentsDb.connectionName());
        }
        catch (const SqlException& exc)
        {
            qDebug()<<exc.err().text();
        }
    }
}
dataBase::dataBase(QObject *parent) :
    QObject(parent)
{
    dbase = QSqlDatabase::addDatabase("QSQLITE", "calc.db");
    dbase.setDatabaseName("calc.db");
    agentsDb = QSqlDatabase::addDatabase("QSQLITE", "agents.db");
    agentsDb.setDatabaseName("agents.db");
}
dataBase::~dataBase()
{
    dbase.commit();
    dbase.close();
}

void dataBase::connectDB()
{
    if (!dbase.open()) {
        qDebug() << "Что-то не так с соединением!";
        throw std::runtime_error("Cant connect to db");
    }
    if (!agentsDb.open()) {
        qDebug() << "Что-то не так с соединением!";
        throw std::runtime_error("Cant connect to agentsdb");
    }
}
dataBase::dataBase(const QString &name, QObject *parent)
{
    dbase = QSqlDatabase::addDatabase("QSQLITE", name);
    dbase.setDatabaseName(name);
}
std::shared_ptr<QSqlQuery> dataBase::query(const QString &q)
{
    return query(q, dbase.connectionName());
}

std::shared_ptr<QSqlQuery> dataBase::query(const QString& q, const QString& dbName)
{
    std::shared_ptr<QSqlQuery> db_query(new QSqlQuery("", QSqlDatabase::database(dbName)));
    if(db_query->exec(q))
    {
        return db_query;
    }
    throw SqlException(db_query->lastError(), q);
}
