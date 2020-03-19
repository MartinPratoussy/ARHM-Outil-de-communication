#include "user.h"

User::User(QString firstname, QString lastname, QString birthDate, QString handicap)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDate = birthDate;
    this->handicap = handicap;

    // Ajout des attributs dans la table User de a base de données
    QSqlQuery query;
    if(!query.exec("INSERT INTO user VALUES ('"
                  + this->firstname + "', '"
                  + this->lastname + "', '"
                  + this->birthDate + "', '"
                  + this->handicap + ")"))
            qWarning() << "ERROR: " << query.lastError().text();
}

QString User::getFirstname()
{
    return this->firstname;
}

QString User::getLastname()
{
    return this->lastname;
}

QString User::getBirthDate()
{
    return this->birthDate;
}

QString User::getHandicap()
{
    return this->handicap;
}

void User::setFirstname(QString firstname, QSqlQuery* query)
{
    this->firstname = firstname;
    if (!query->exec("UPDATE user SET firstname = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setLastname(QString lastname, QSqlQuery* query)
{
    this->lastname = lastname;
    if (!query->exec("UPDATE user SET lastname = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setBirthDate(QString birthDate, QSqlQuery* query)
{
    this->birthDate = birthDate;
    if (!query->exec("UPDATE user SET birthDate = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setHandicap(QString handicap, QSqlQuery* query)
{
    this->handicap = handicap;
    if (!query->exec("UPDATE user SET handicap = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}


User & User::operator=(const User &user)
{
    this->firstname = user.firstname;
    this->lastname = user.lastname;
    this->birthDate = user.birthDate;
    this->handicap = user.handicap;
    //**this->pictos = **user.pictos;

    return * this;
}
