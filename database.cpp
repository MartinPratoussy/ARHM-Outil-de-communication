#include "database.h"

Database::Database()
{
    // Connexion à la base de données
    const QString DRIVER("QSqlite");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        this->db = QSqlDatabase::addDatabase(DRIVER);
        this->db.setDatabaseName("/database.db");
        if(!this->db.open()) qWarning() << "ERROR: " << db.lastError();

    }
}

QSqlDatabase Database::getDB()
{
    return this->db;
}
