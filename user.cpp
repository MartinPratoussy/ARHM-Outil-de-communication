#include "user.h"

User::User()
{

}

User::User(QString firstname, QString lastname, QDate birthDate, QString handicap)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDate = birthDate;
    this->handicap = handicap;
    nbUser++;
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

Interface User::getInterface()
{
    return this->interface;
}

User & User::operator=(const User &user)
{
    this->firstname = user.firstname;
    this->lastname = user.lastname;
    this->birthDate = user.birthDate;
    this->handicap = user.handicap;
    this->interface = user.interface;

    return * this;
}
