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
}


User::~User()
{

}

