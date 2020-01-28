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
        if (User::nbUser >= NB_MAX_USER - 1)
        {
            throw "Trop d'utlisateurs enregistrés";
        }
        this->user[User::nbUser] = user;
        User::nbUser++;
    } catch (std::exception e)
    {
        std::cerr << e.what();
    }
}

void UserList::EditUser(User user)
{
    // Envoie de l'utlisateur à éditer à la page d'édition
}

void UserList::on_edits_clicked()
{

}
