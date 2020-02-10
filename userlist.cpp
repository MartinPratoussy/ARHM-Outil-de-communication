#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    Database db;

    // Récupère les utilisateurs enregistrés dans la base de données
    for (int i = 0; i < NB_MAX_USER; i++) {
        QSqlQuery query(db.db);
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
        this->user[i] = new User(firstname, lastname, birthDate, handicap);
        nbUser++;
        // Vérifie dans la console le nom de l'utilisateur retourné
        qInfo() << this->user[i]->getFirstname();
    }
}

UserList::~UserList()
{
    delete ui;
}

void UserList::on_pushButton_clicked()
{
    Interface * interface = new Interface();
    interface->InitInterface(user[0]);
    interface->show();
}
