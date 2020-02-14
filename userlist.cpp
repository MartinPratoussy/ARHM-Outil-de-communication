#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    this->addUserButton = new QPushButton(this);

    // Initialise la base de données à utiliser
    QSqlDatabase * database = new QSqlDatabase();
    const QString DRIVER("QSqlite");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        *database = QSqlDatabase::addDatabase(DRIVER);
        database->setDatabaseName("/database.db");
        if(!database->open()) qWarning() << "ERROR: " << database->lastError();
    }

    // Génère un objet query qui contiendra les prochaines requêtes
    QSqlQuery query;
    // Récupère le nombre d'utilisateurs
    if(!query.exec("SELECT COUNT(*) FROM User;")) qWarning() << "ERROR: " << database->lastError();
    this->nbUser = query.value(0).toInt();

    // Récupère les valeurs des utilisateurs enregistrés dans la base de données
    /*for (int i = 0; i < this->nbUser; i++) {
        if(!query.exec("SELECT firstname FROM user WHERE id = " + QString(i) + ")")) qWarning() << "ERROR: " << database->lastError();
        QString firstname = query.value(0).toString();
        if(!query.exec("SELECT lastname FROM user WHERE id = " + QString(i) + ")")) qWarning() << "ERROR: " << database->lastError();
        QString lastname = query.value(0).toString();
        if(!query.exec("SELECT birthdate FROM user WHERE id = " + QString(i) + ")")) qWarning() << "ERROR: " << database->lastError();
        QDate birthDate = query.value(0).toDate();
        if(!query.exec("SELECT handicap FROM user WHERE id = " + QString(i) + ")")) qWarning() << "ERROR: " << database->lastError();
        QString handicap = query.value(0).toString();
        if(!query.exec("SELECT interface FROM user WHERE id = " + QString(i) + ")")) qWarning() << "ERROR: " << database->lastError();
        QString interface = query.value(0).toString();

        // Ajoute les valeurs retournées à l'utlisateur de l'interface
        this->interface[i]->GetUser()->setFirstname(firstname);
        this->interface[i]->GetUser()->setLastname(lastname);
        this->interface[i]->GetUser()->setBirthDate(birthDate);
        this->interface[i]->GetUser()->setHandicap(handicap);
    }
    ShowUserList();*/

}

UserList::~UserList()
{
    delete ui;
}

void UserList::ShowUserList()
{
    for (int numUser = 0; numUser < nbUser; numUser++) {
        this->button[numUser]->setGeometry(
                    QApplication::desktop()->width()/10,
                    numUser*QApplication::desktop()->height()/10,
                    QApplication::desktop()->width()*4/5,
                    QApplication::desktop()->height()/10);
        this->button[numUser]->show();
    }
    this->addUserButton->setGeometry(
                QApplication::desktop()->width()/10,
                (nbUser+1)*QApplication::desktop()->height()/10,
                QApplication::desktop()->width() * 0.8,
               QApplication::desktop()->height()/10);
    this->addUserButton->show();
}

void UserList::on_pushButton_clicked()
{
    Interface * interface = new Interface();
    interface->InitInterface(interface->GetUser());
    interface->show();
}
