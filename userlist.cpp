#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    // Initaialise la base de données à utiliser
    QSqlDatabase * database = new QSqlDatabase();
    const QString DRIVER("QSqlite");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        *database = QSqlDatabase::addDatabase(DRIVER);
        database->setDatabaseName("/database.db");
        if(!database->open()) qWarning() << "ERROR: " << database->lastError();
    }

    // Génèreun objet query qui contiendra les prochaines requêtes
    QSqlQuery query(*database);
    // Récupère le nombre d'utilisateurs
    if(!query.exec("SELECT COUNT(*) FROM User;")) qWarning() << "ERROR: " << database->lastError();
    this->nbUser = query.value(0).toInt();

    // Récupère les valeurs des utilisateurs enregistrés dans la base de données
    for (int i = 0; i < this->nbUser; i++) {
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
        this->interface[i]->getUser()->setFirstname(firstname);
        this->interface[i]->getUser()->setLastname(lastname);
        this->interface[i]->getUser()->setBirthDate(birthDate);
        this->interface[i]->getUser()->setHandicap(handicap);
    }

}

UserList::~UserList()
{
    delete ui;
}

void UserList::on_pushButton_clicked()
{
    Interface * interface = new Interface();
    //interface->InitInterface(interface.getUser());
    interface->show();
}
