#include "useredits.h"
#include "ui_useredits.h"

UserEdits::UserEdits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEdits)
{
    ui->setupUi(this);
}

UserEdits::~UserEdits()
{
    delete ui;
}

void UserEdits::EditFirstname(QString firstname)
{
    user->getFirstname() = firstname;
}

void UserEdits::EditLastname(QString lastname)
{
    user->getLastname() = lastname;
}

void UserEdits::EditBirthDate(QDate birthDate)
{
    user->getBirthDate() = birthDate;
}

void UserEdits::EditHandicap(QString handicap)
{
    user->getHandicap() = handicap;
}

void UserEdits::AddPicto(Pictogram picto)
{

}

void UserEdits::DeleteUser()
{
    try
    {
        if (User::nbUser < 1)
        {
            throw "Aucun utlisateur à supprimer";
        }
    } catch (std::exception e)
    {
        std::cerr << e.what();
    }
    User::nbUser--;
    user->~User();
}

