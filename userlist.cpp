#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::UserList)
{
	ui->setupUi(this);

#pragma region ConnexionBDD
	// Initialise la base de données à utiliser
    database = new QSqlDatabase();
	const QString DRIVER("QSQLITE");
	if (QSqlDatabase::isDriverAvailable(DRIVER))
	{
		// Défini le SGBD utilisée
		*database = QSqlDatabase::addDatabase(DRIVER);
		// Se connecte à la base de données à utiliser
		database->setDatabaseName("database.db");
		// Ouvre la base de données
		if (!database->open()) qWarning() << "ERROR: " << database->lastError().text();
	}
	else qWarning() << "ERROR: " << database->lastError().text();
#pragma endregion /*Connecte l'application à la base de données*/

#pragma region getUser
	// Génère un objet query qui contiendra les prochaines requêtes
    query = new QSqlQuery(*database);
	// Récupère les utilisateurs dans la base de données
    if (!query->exec("SELECT * FROM \"User\"")) qWarning() << "ERROR: " << database->lastError().text();
	// Tant qu'il y a des utilisateurs, le nombre d'utilisateur s'incrémente
    while (query->next()) nbUser++;

	// nbUser prend la valeur du nombre de lignes dans la base de données
	qDebug() << "Nombre d'utilisateurs : " << this->nbUser;

	// Récupère les valeurs des utilisateurs enregistrés dans la base de données et les ajoute aux utilisateurs dans le programme
	for (int i = 1; i <= this->nbUser; i++) {
        if (!query->exec("SELECT firstname FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) this->interface[i]->GetUser()->setFirstname(query->value(0).toString(), query);
        if (!query->exec("SELECT lastname FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) this->interface[i]->GetUser()->setLastname(query->value(0).toString(), query);
        if (!query->exec("SELECT birthdate FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) this->interface[i]->GetUser()->setBirthDate(query->value(0).toDate(), query);
        if (!query->exec("SELECT handicap FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) this->interface[i]->GetUser()->setHandicap(query->value(0).toString(), query);
	}

    nbUser = 6;
#pragma endregion

#pragma region setDisplay
	// Initialisation de la taille de la fenêtre
	this->width = QApplication::desktop()->width();
	this->height = QApplication::desktop()->height();
	QApplication::desktop()->setGeometry(0, 0, this->width, this->height + this->height * (1 / 3) * nbUser);

	this->area = new QScrollArea(this);
	area->setWidgetResizable(true);
	area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	ShowUserList();

	area->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
#pragma endregion /*Affiche l'interface du menu principal*/
}

UserList::~UserList()
{
	delete ui;
}

void UserList::ShowUserList()
{
#pragma region DisplayButtons
    // Place chacun des boutons de l'interface
	for (int numUser = 0; numUser < nbUser; numUser++) {
        // Crée les boutons d'accès aux interfaces utilisateurs
        interfaceButton[numUser] = new QPushButton(this);
        // Crée les boutons d'accès aux interfaces d'édition
        editButton[numUser] = new QPushButton(this);
        // Place les boutons d'accès aux interfaces utilisateurs
        this->interfaceButton[numUser]->setGeometry(
			this->width / 10,
			numUser * this->height / 10,
			this->width * 4 / 5,
			this->height / 10);
        // Place les boutons d'accès aux interfaces utilisateurs
        this->editButton[numUser]->setGeometry(
                    8 * this->width / 10,
                    numUser * this->height / 10,
                    this->width / 10,
                    this->height / 10);
        // Affiche les boutons
        this->interfaceButton[numUser]->show();
        this->editButton[numUser]->show();
        connect(interfaceButton[numUser], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(numUser)));
        connect(editButton[numUser], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(numUser)));
	}
	// Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
    this->addUserButton = new QPushButton(this);
	this->addUserButton->setGeometry(
		this->width / 10,
		(nbUser + 1) * this->height / 10,
		this->width * 0.8,
		this->height / 10);
	this->addUserButton->show();

#pragma endregion
}

void UserList::on_interfaceButton_clicked(int numUser)
{
    interface[numUser] = new Interface();
    interface[numUser]->InitInterface(interface[numUser]->GetUser());
    interface[numUser]->show();
}

void UserList::on_editButton_clicked(int numUser)
{
    userEdits[numUser] = new UserEdits();
    userEdits[numUser]->InitUserEditsInterface(userEdits[numUser]->GetUser(), this->query);
    userEdits[numUser]->show();
}

void UserList::on_addButton_clicked()
{

}
