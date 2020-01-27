#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);
}

UserList::~UserList()
{
    delete ui;
}

void UserList::AddUser(User user)
{
    try
    {
        if (nbUser >= NB_MAX_USER - 1)
        {
            throw "Trop d'utlisateurs enregistrés";
        }
        this->user[nbUser] = user;
        nbUser++;
    } catch (std::exception e)
    {
        std::cerr << e.what();
    }

}

void UserList::DeleteUser(User user)
{
    try
    {
        if (nbUser < 1)
        {
            throw "Aucun utlisateur à supprimer";
        }
    } catch (std::exception e)
    {
        std::cerr << e.what();
    }
    user.~User();
    nbUser--;
}
