#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::UserList)
{
	ui->setupUi(this);

	ConnectToDatabase();
	LoadUsers();
	SetDisplayGeometry();
	ShowUserList();
}

void UserList::ConnectToDatabase()
{
	// Initialise la base de données à utiliser
	database = new QSqlDatabase();
	const QString DRIVER("QSQLITE");
	if (QSqlDatabase::isDriverAvailable(DRIVER))
	{
		// Défini le SGBD utilisé
		*database = QSqlDatabase::addDatabase(DRIVER);
		// Se connecte à la base de données à utiliser
		database->setDatabaseName("database.db");
		// Ouvre la base de données
		if (!database->open()) qWarning() << "ERROR: " << database->lastError().text();
	}
	else qWarning() << "ERROR: " << database->lastError().text();
}

void UserList::LoadUsers()
{
	// Génère un objet query qui contiendra les prochaines requêtes
	query = new QSqlQuery(*database);
	// Récupère les utilisateurs dans la base de données
	if (!query->exec("SELECT * FROM \"User\"")) qWarning() << "ERROR: " << database->lastError().text();
	// Tant qu'il y a des utilisateurs, le nombre d'utilisateur s'incrémente
	while (query->next()) nbUser++;

	nbUser = 5;

	// nbUser prend la valeur du nombre de lignes dans la base de données
	qDebug() << "Nombre d'utilisateurs : " << this->nbUser;

	// Récupère les valeurs des utilisateurs enregistrés dans la base de données et les ajoute aux utilisateurs dans le programme
	int id;
	QString firstname, lastname, birthDate, handicap;
	for (int i = 1; i <= this->nbUser; i++) {
		if (!query->exec("SELECT userId FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) id = query->value(0).toInt();
		if (!query->exec("SELECT firstname FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) firstname = query->value(0).toString();
		if (!query->exec("SELECT lastname FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) lastname = query->value(0).toString();
		if (!query->exec("SELECT birthdate FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) birthDate = query->value(0).toString();
		this->user[i] = new User(id, firstname, lastname, birthDate, database, query);
	}
}

void UserList::SetDisplayGeometry()
{
	// Initialisation de la taille de la fenêtre
	this->width = QApplication::desktop()->width();
	this->height = QApplication::desktop()->height();
	QApplication::desktop()->setGeometry(0, 0, this->width, this->height + this->height * (1 / NB_USER_DISPLAYABLE) * nbUser);

	this->area = new QScrollArea(this);
	area->setWidgetResizable(true);
	area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	area->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
}

UserList::~UserList()
{
	delete ui;
}

void UserList::ShowUserList()
{
	// Place chacun des boutons de l'interface
	for (int numUserY = 0; numUserY < nbUser / 4; numUserY++) 
	{
		for (int numUserX = 0; numUserX < 4; numUserX++)
		{
			// Crée les boutons d'accès aux interfaces utilisateurs
			interfaceButton[numUserX + numUserY] = new QPushButton(this);
			// Crée les boutons d'accès aux interfaces d'édition
			editButton[numUserX + numUserY] = new QPushButton(this);

			// Position et taille des boutons d'accès aux interfaces utilisateur
			int posX = this->width / 17 + 4 * numUserX * this->width / 17;
			int posY = this->height / 9 + 4 * numUserY * this->height / 9;
			int sizeX = this->width * 3 / 17;
			int sizeY = this->height * 3 / 9;

			// Place les boutons d'accès aux interfaces utilisateurs
			this->interfaceButton[numUserX + numUserY]->setGeometry(posX, posY, sizeX, sizeY);

			// Place les boutons d'accès aux interfaces utilisateurs
			this->editButton[numUserX + numUserY]->setGeometry(
				posX + this->width / 17,
				posY + this->height * 3/9, 
				this->width / 18, 
				this->height / 18);

			// Affiche les boutons
			this->interfaceButton[numUserX + numUserY]->show();
			this->editButton[numUserX + numUserY]->show();

			// Attribue aux boutons des méthodes de la classse
			connect(interfaceButton[numUserX + numUserY], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(/*this, numUserX + numUserY*/)));
			connect(editButton[numUserX + numUserY], SIGNAL(released()), this, SLOT(on_addButton_clicked(/*this, */numUserX + numUserY)));
		}
	}
	// Place les boutons qui n'ont pas été placés dans la boucle for précédente
	for (int numUser = 0; numUser < nbUser % 4; numUser++)
	{
		// Crée les boutons d'accès aux interfaces utilisateurs
		interfaceButton[(nbUser / 4) + numUser] = new QPushButton(this);
		// Crée les boutons d'accès aux interfaces d'édition
		editButton[(nbUser / 4) + numUser] = new QPushButton(this);

		int posX = this->width / 17 + 4 * numUser * this->width / 17;
		int posY = this->height / 9 + 4 * (nbUser / 4) * this->height / 9;
		int sizeX = this->width * 3 / 17;
		int sizeY = this->height * 3 / 9;

		this->interfaceButton[(nbUser / 4) + numUser]->setGeometry(posX, posY, sizeX, sizeY);
		this->editButton[(nbUser / 4) + numUser]->setGeometry(posX, posY, sizeX, sizeY);

		connect(interfaceButton[(nbUser / 4) + numUser], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(this, (nbUser / 4) + numUser, )));
		connect(editButton[(nbUser / 4) + numUser], SIGNAL(released()), this, SLOT(on_editButton_clicked(this, (nbUser / 4) + numUser)));
	}
	// Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
	this->addUserButton = new QPushButton(this);
	this->addUserButton->setGeometry(
		this->width / 17 + nbUser * (1 / 4) * this->width / 17,
		(nbUser + 1) * (this->height / 9 + nbUser * (1 / 2) * this->height / 9),
		this->width * 3 / 17,
		this->height / 3);
	this->addUserButton->show();
	connect(addUserButton, SIGNAL(released()), this, SLOT(on_addButton_clicked(/*this*/)));
}

void UserList::on_interfaceButton_clicked(/*UserList* userList, int numUser*/)
{
	interface = new Interface();
	User* user = new User(0, "test", "test", "01/01/2000", database, query);
	interface->InitInterface(user);
	interface->show();
}

void UserList::on_editButton_clicked(/*UserList* userList, */int numUser)
{
	userEdits = new EditUser(user[numUser]);
	userEdits->InitInterface(this->query);
	userEdits->show();
}

void UserList::on_addButton_clicked(/*UserList* userList*/)
{
	addUser = new AddUser(this->database, this->query);
	addUser->show();
}
