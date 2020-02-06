#include "user.h"

User::User(QString firstname, QString lastname, QDate birthDate, QString handicap)
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
                  + this->birthDate.toString("dd.MM.yyyy") + "', '"
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

QDate User::getBirthDate()
{
    return this->birthDate;
}

QString User::getHandicap()
{
    return this->handicap;
}

void User::setFirstname(QString firstname)
{
    this->firstname = firstname;
    query(this->firstname);
}

void User::setLastname(QString lastname)
{
    this->lastname = lastname;
    query(this->lastname);
}

void User::setBirthDate(QDate birthDate)
{
    this->birthDate = birthDate;
    query(this->birthDate.toString());
}

void User::setHandicap(QString handicap)
{
    this->handicap = handicap;
    query(this->handicap);
}

void User::query(QString value)
{
    QSqlQuery query;
    if (!query.exec("UPDATE user SET firstname = '" + value + "'")) qWarning() << "ERROR : " << query.lastError().text();
}

User & User::operator=(const User &user)
{
    this->firstname = user.firstname;
    this->lastname = user.lastname;
    this->birthDate = user.birthDate;
    this->handicap = user.handicap;

    return * this;
}
