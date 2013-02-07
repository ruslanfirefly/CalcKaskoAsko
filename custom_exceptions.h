#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H
#include <stdexcept>
#include <QString>
#include <QSqlError>
class SqlException : public std::exception
{
public:
    SqlException(const QString& msg) throw() : std::exception(), message(msg.toStdString())
    {

    }
    SqlException(const QSqlError& err) throw() : std::exception(), message(err.text().toStdString()), error(err)
    {

    }
    SqlException(const QSqlError& err, const QString& query) : SqlException(err)
    {
        query_text = query;
    }
    ~SqlException() throw() {}
    const char* what() const throw() { return  message.c_str(); }
    const QSqlError& err() const throw() { return error; }
    const QString& text() const throw() { return query_text; }
private:
    std::string message;
    QSqlError error;
    QString query_text;
};

#endif // CUSTOM_EXCEPTIONS_H
