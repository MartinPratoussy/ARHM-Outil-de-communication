#ifndef DATABASE_H
#define DATABASE_H

#include "includes.h"

class Database
{
public:
    Database();

    QSqlDatabase db;
};

#endif // DATABASE_H
