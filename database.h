#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

class Database
{
private:
    QSqlDatabase db;
public:
    Database();

    // Getter de la base de données
    QSqlDatabase getDB();

};

#endif // DATABASE_H
