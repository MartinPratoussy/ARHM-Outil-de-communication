#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    // Récupère les utilisateurs enregistrés dans la base de données
    for (int i = 0; i < NB_MAX_USER; i++) {
        QSqlQuery query;
        query.exec("SELECT firstname FROM user WHERE id = " + QString(i) + ")");
        QString firstname = query.value(0).toString();
        query.exec("SELECT lastname FROM user WHERE id = " + QString(i) + ")");
        QString lastname = query.value(0).toString();
        query.exec("SELECT birthdate FROM user WHERE id = " + QString(i) + ")");
        QDate birthDate = query.value(0).toDate();
        query.exec("SELECT handicap FROM user WHERE id = " + QString(i) + ")");
        QString handicap = query.value(0).toString();
        query.exec("SELECT interface FROM user WHERE id = " + QString(i) + ")");
        QString interface = query.value(0).toString();
        // Crée un nouvel utilisateur avec les données de la base de données
        this->user[i] = new User(firstname, lastname, birthDate, handicap, interface);
    }
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
        *this->user[User::nbUser] = user;
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
