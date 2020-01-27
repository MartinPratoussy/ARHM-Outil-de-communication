#include "user.h"

user::user()
{

}

user::user(QString firstname, QString lastname, QDate birthDate, QString handicap)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDate = birthDate;
    this->handicap = handicap;
}


user::~user()
{

}

