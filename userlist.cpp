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
	this->interfaceMapper = new QSignalMapper();
	this->editMapper = new QSignalMapper();
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
		if (!database->open()) qWarning() << "ERROR: database not open";
	}
	else qWarning() << "ERROR: driver not available";
}

void UserList::LoadUsers()
{
	// Génère un objet query qui contiendra les prochaines requêtes
	query = new QSqlQuery(*database);
	// Récupère les utilisateurs dans la base de données
	if (!query->exec("SELECT idUser FROM \"User\"")) qWarning() << "ERROR: idUser not found";
	// Tant qu'il y a des utilisateurs, le nombre d'utilisateur s'incrémente
	while (query->next()) {
		usersId.append(query->value(0).toInt());
	}
	// Le nombre d'utlisateur est égal au nombre d'id que la requête a retourné
	this->nbUser = usersId.count();

	// nbUser prend la valeur du nombre de lignes dans la base de données
	qDebug() << "Nombre d'utilisateurs : " << this->nbUser;

	// Récupère les valeurs des utilisateurs enregistrés dans la base de données et les ajoute aux utilisateurs dans le programme
	QString firstname, lastname, birthDate, handicap;
	for each(int i in usersId) {
		if (!query->exec("SELECT firstname FROM User WHERE idUser = " + QString::number(i) + " ;")) qWarning() << "ERROR: firstname for user" + QString::number(i) + "not found";
		while (query->next()) firstname = query->value(0).toString();
		qDebug() << "firstname = " << firstname;
		if (!query->exec("SELECT lastname FROM \"User\" WHERE idUser = " + QString::number(i) + " ;")) qWarning() << "ERROR: lastname for user" + QString::number(i) + "not found";
		while (query->next()) lastname = query->value(0).toString();
		qDebug() << "lastname = " << lastname;
		if (!query->exec("SELECT birthdate FROM \"User\" WHERE idUser = " + QString::number(i) + " ;")) qWarning() << "ERROR: birthdate for user" + QString::number(i) + "not found";
		while (query->next()) birthDate = query->value(0).toString();
		qDebug() << "birthDate = " << birthDate;
		this->user[i] = new User(i, firstname, lastname, birthDate, database, query);
	}
}

void UserList::SetDisplayGeometry()
{
	// Initialisation de la taille de la fenêtre
	/*ui->scrollArea->setGeometry(0, 0, this->width, this->height + this->height * (1 / NB_USER_DISPLAYABLE) * nbUser);
	ui->scrollArea->show();*/
}

UserList::~UserList()
{
	delete ui;
}

void UserList::ShowUserList()
{
	// Place chacun des boutons de l'interface
	for (int numUserY = 0; numUserY < 2 * nbUser / NB_USER_DISPLAYABLE; numUserY++)
	{
		for (int numUserX = 0; numUserX < NB_USER_DISPLAYABLE / 2; numUserX++)
		{
			// Crée les boutons d'accès aux interfaces utilisateurs
			interfaceButton[numUserX + numUserY] = new QPushButton(this/*ui->scrollArea*/);
			// Crée les boutons d'accès aux interfaces d'édition
			editButton[numUserX + numUserY] = new QPushButton(this/*ui->scrollArea*/);

			// Position et taille des boutons d'accès aux interfaces utilisateur
			int posX = this->geometry().height() / WIDTH_PIECES + NB_USER_DISPLAYABLE / 2 * numUserX * this->geometry().width() / WIDTH_PIECES;
			int posY = this->geometry().height() / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * numUserY * this->geometry().height() / HEIGHT_PIECES;
			int sizeX = this->geometry().width() * 3 / WIDTH_PIECES;
			int sizeY = this->geometry().height() * 3 / HEIGHT_PIECES;

			// Place les boutons d'accès aux interfaces utilisateurs
			this->interfaceButton[numUserX + numUserY]->setGeometry(posX, posY, sizeX, sizeY);

			// Place les boutons d'accès aux interfaces utilisateurs
			this->editButton[numUserX + numUserY]->setGeometry(
				posX + this->geometry().width() / WIDTH_PIECES,
				posY + this->geometry().height() * 3 / HEIGHT_PIECES,
				this->geometry().width() / 18,
				this->geometry().height() / 18);

			// Affiche les boutons
			this->interfaceButton[numUserX + numUserY]->show();
			this->editButton[numUserX + numUserY]->show();

			// Attribue aux boutons des slots paramétrés de la classse
			// Boutons d'interface
			connect(interfaceButton[numUserX + numUserY], SIGNAL(released()), this->interfaceMapper, SLOT(map()));
			this->interfaceMapper->setMapping(interfaceButton[numUserX + numUserY], numUserX + numUserY);

			// Boutons d'édtion
			connect(editButton[numUserX + numUserY], SIGNAL(released()), this->editMapper, SLOT(map()));
			this->editMapper->setMapping(editButton[numUserX + numUserY], numUserX + numUserY);
		}
	}
	// Place les boutons qui n'ont pas été placés dans la boucle for précédente
	for (int numUser = 0; numUser < nbUser % NB_USER_DISPLAYABLE / 2; numUser++)
	{
		// Crée les boutons d'accès aux interfaces utilisateurs
		interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser] = new QPushButton(ui->scrollArea);
		// Crée les boutons d'accès aux interfaces d'édition
		editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser] = new QPushButton(ui->scrollArea);

		int posX = this->geometry().width() / WIDTH_PIECES + NB_USER_DISPLAYABLE / 2 * numUser * this->width / WIDTH_PIECES;
		int posY = this->geometry().height() / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * (2 * nbUser / NB_USER_DISPLAYABLE) * this->height / HEIGHT_PIECES;
		int sizeX = this->geometry().width() * 3 / WIDTH_PIECES;
		int sizeY = this->geometry().height() * 3 / HEIGHT_PIECES;

		this->interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser]->setGeometry(posX, posY, sizeX, sizeY);
		this->editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser]->setGeometry(posX, posY, sizeX, sizeY);

		connect(interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], SIGNAL(released()), this->interfaceMapper, SLOT(map()));
		this->interfaceMapper->setMapping(interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], (2 * nbUser / NB_USER_DISPLAYABLE) + numUser);

		connect(editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], SIGNAL(released()), this->editMapper, SLOT(map()));
		this->editMapper->setMapping(editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], (2 * nbUser / NB_USER_DISPLAYABLE) + numUser);
	}

	// Connecte les mappeurs aux slots paramétré
	connect(this->interfaceMapper, SIGNAL(mapped(int)), this, SLOT(on_interfaceButton_clicked()));
	connect(this->editMapper, SIGNAL(mapped(int)), this, SLOT(on_editButton_clicked()));

	// Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
	this->addUserButton = new QPushButton(ui->scrollArea);
	this->addUserButton->setGeometry(
		this->geometry().width() / WIDTH_PIECES + nbUser * (2 / NB_USER_DISPLAYABLE) * this->geometry().width() / WIDTH_PIECES,
		(nbUser + 1) * (this->geometry().height() / HEIGHT_PIECES + nbUser * (2 / NB_USER_DISPLAYABLE) * this->geometry().height() / HEIGHT_PIECES),
		this->geometry().width() * 3 / WIDTH_PIECES,
		this->geometry().height() / 3);
	this->addUserButton->show();
	connect(this->addUserButton, SIGNAL(released()), this, SLOT(on_addButton_clicked()));
}

void UserList::on_interfaceButton_clicked(int numUser)
{
	interface = new Interface();
	interface->InitInterface(user[numUser]);
	interface->show();
}

void UserList::on_editButton_clicked(int numUser)
{
	userEdits = new EditUser(user[0]);
	userEdits->InitInterface(this->query);
	userEdits->show();
}

void UserList::on_addButton_clicked()
{
	addUser = new AddUser(this->database, this->query);
	addUser->show();
}
