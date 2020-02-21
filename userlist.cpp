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
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        // Défini la SGBD utilisée
        *database = QSqlDatabase::addDatabase(DRIVER);
        // Se connecte à la base de données à utiliser
        database->setDatabaseName("database.db");
        // Ouvre la base de données
        if(!database->open()) qWarning() << "ERROR: " << database->lastError().text();
    } else qWarning() << "ERROR: " << database->lastError().text();

    // Génère un objet query qui contiendra les prochaines requêtes
    QSqlQuery query(*database);
    // Récupère le nombre d'utilisateurs dans la base de données
    if(!query.exec("SELECT COUNT(*) FROM \"User\"")) qWarning() << "ERROR: " << database->lastError().text();
    while(!query.next()) { qWarning() << "oui" ; this->nbUser = query.value(0).toInt();}
    // nbUser prend la valeur du nombre de lignes dans la base de données
    qDebug() << "Nombre d'utilisateurs : " << this->nbUser;

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
        this->interface[i]->GetUser()->setFirstname(firstname);
        this->interface[i]->GetUser()->setLastname(lastname);
        this->interface[i]->GetUser()->setBirthDate(birthDate);
        this->interface[i]->GetUser()->setHandicap(handicap);
    }

    // Initialisation de la taille de la fenêtre
    this->width = QApplication::desktop()->width();
    this->height = QApplication::desktop()->height();
    QApplication::desktop()->setGeometry(0, 0, this->width, this->height + this->height * (1/3) * nbUser);

    this->area = new QScrollArea(this);
    area->setWidgetResizable(true);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ShowUserList();

    area->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
}

UserList::~UserList()
{
    delete ui;
}

void UserList::ShowUserList()
{
    // Place chacun des boutons d'accès aux interfaces utilisateurs
    for (int numUser = 0; numUser < nbUser; numUser++) {
        button[numUser] = new QPushButton(this->area);
        this->button[numUser]->setGeometry(
                    this->width/10,
                    numUser * this->height/10,
                    this->width * 4/5,
                    this->height/10);
        this->button[numUser]->show();
    }
    // Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
    this->addUserButton->setGeometry(
                this->width/10,
                (nbUser + 1) * this->height/10,
                this->width * 0.8,
                this->height/10);
    this->addUserButton->show();

}

void UserList::on_pushButton_clicked()
{
    Interface * interface = new Interface();
    interface->InitInterface(interface->GetUser());
    interface->show();
}
