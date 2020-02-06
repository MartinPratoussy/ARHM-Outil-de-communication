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
    this->user->setFirstname(firstname);
}

void UserEdits::EditLastname(QString lastname)
{
    this->user->setLastname(lastname);
}

void UserEdits::EditBirthDate(QDate birthDate)
{
    this->user->setBirthDate(birthDate);
}

void UserEdits::EditHandicap(QString handicap)
{
    this->user->setHandicap(handicap);
}

void UserEdits::DeleteUser()
{
    try
    {
        if (/*nbUser < */1)
        {
            throw "Aucun utlisateur à supprimer";
        }
    } catch (std::exception e)
    {
        std::cerr << e.what();
    }
    //nbUser--;
    user->~User();
}
