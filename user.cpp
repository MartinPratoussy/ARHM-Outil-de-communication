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

void User::EditFirstname(QString firstname)
{
    this->firstname = firstname;
}

void User::EditLastname(QString lastname)
{
    this->lastname = lastname;
}

void User::EditBirthDate(QDate birthDate)
{
    this->birthDate = birthDate;
}

void User::EditHandicap(QString handicap)
{
    this->handicap = handicap;
}

void User::DeleteUser()
{
    this->~User();
}
