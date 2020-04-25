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
	int numUser = 0;
	QString firstname, lastname, birthDate, handicap;
	for each(int id in usersId) {
		if (!query->exec("SELECT firstname FROM User WHERE idUser = " + QString::number(id) + ";")) qWarning() << "ERROR: firstname for user" + QString::number(id) + "not found";
		while (query->next()) firstname = query->value(0).toString();
		qDebug() << "firstname = " << firstname;
		if (!query->exec("SELECT lastname FROM \"User\" WHERE idUser = " + QString::number(id) + ";")) qWarning() << "ERROR: lastname for user" + QString::number(id) + "not found";
		while (query->next()) lastname = query->value(0).toString();
		qDebug() << "lastname = " << lastname;
		if (!query->exec("SELECT birthdate FROM \"User\" WHERE idUser = " + QString::number(id) + ";")) qWarning() << "ERROR: birthdate for user" + QString::number(id) + "not found";
		while (query->next()) birthDate = query->value(0).toString();
		qDebug() << "birthDate = " << birthDate;
		this->user[numUser] = new User(id, firstname, lastname, birthDate, database, query);
		numUser++;
	}
}

void UserList::SetDisplayGeometry()
{
	// Initialisation de la taille de la fenêtre
	this->width = ui->scrollArea->width();
	this->height = ui->scrollArea->height();

	// Le conteneur est implémenté à la zone de scrolling
	content = new QWidget(this);
	ui->scrollArea->setWidget(content);

	// Initialisation de la taille du conteneur
	ui->scrollArea->widget()->setMinimumSize(this->width, this->height);
	ui->scrollArea->widget()->setGeometry(ui->scrollArea->x(), ui->scrollArea->y(), this->width, this->height + this->height * ((nbUser + 1) / NB_USER_DISPLAYABLE));
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
			interfaceButton[numUserX + numUserY] = new QPushButton(content);
			// Crée les boutons d'accès aux interfaces d'édition
			editButton[numUserX + numUserY] = new QPushButton(content);

			// Position et taille des boutons d'accès aux interfaces utilisateur
			int posX = this->height / WIDTH_PIECES + NB_USER_DISPLAYABLE / 2 * numUserX * this->width / WIDTH_PIECES;
			int posY = this->height / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * numUserY * this->height / HEIGHT_PIECES;
			int sizeX = this->width * 3 / WIDTH_PIECES;
			int sizeY = this->height * 3 / HEIGHT_PIECES;

			// Place les boutons d'accès aux interfaces utilisateurs
			this->interfaceButton[numUserX + numUserY]->setGeometry(posX, posY, sizeX, sizeY);

			// Place les boutons d'accès aux interfaces utilisateurs
			this->editButton[numUserX + numUserY]->setGeometry(
				posX + this->width / WIDTH_PIECES,
				posY + this->height * 3 / HEIGHT_PIECES,
				this->width / 18,
				this->height / 18);

			// Affiche les boutons
			this->interfaceButton[numUserX + numUserY]->show();
			this->editButton[numUserX + numUserY]->show();

			// Attribue aux boutons des slots paramétrés de la classse
			connect(this->interfaceButton[numUserX + numUserY], &QPushButton::released, [=] {
				on_interfaceButton_clicked(numUserX + numUserY);
			});

			connect(this->editButton[numUserX + numUserY], &QPushButton::released, [=] {
				on_editButton_clicked(numUserX + numUserY);
			});
		}
	}
	// Place les boutons qui n'ont pas été placés dans la boucle for précédente
	for (int numUser = 0; numUser < nbUser % (NB_USER_DISPLAYABLE / 2); numUser++)
	{
		// Crée les boutons d'accès aux interfaces utilisateurs
		interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser] = new QPushButton(content);
		// Crée les boutons d'accès aux interfaces d'édition
		editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser] = new QPushButton(content);

		int posX = this->width / WIDTH_PIECES + NB_USER_DISPLAYABLE / 2 * numUser * this->width / WIDTH_PIECES;
		int posY = this->height / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * (2 * nbUser / NB_USER_DISPLAYABLE) * this->height / HEIGHT_PIECES;
		int sizeX = this->width * 3 / WIDTH_PIECES;
		int sizeY = this->height * 3 / HEIGHT_PIECES;

		this->interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser]->setGeometry(posX, posY, sizeX, sizeY);
		this->editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser]->setGeometry(posX, posY, sizeX, sizeY);

		// Attribue aux boutons des slots paramétrés de la classse
		connect(interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], &QPushButton::released, [=] {
			on_interfaceButton_clicked((2 * nbUser / NB_USER_DISPLAYABLE) + numUser);
		});

		connect(editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], &QPushButton::released, [=] {
			on_editButton_clicked((2 * nbUser / NB_USER_DISPLAYABLE) + numUser);
		});
	}

	// Création du bouton d'ajout d'utilisateur
	addUserButton = new QPushButton(content);

	// Placement du bouton d'ajout d'utilisateur
	int posX = this->width / WIDTH_PIECES + NB_USER_DISPLAYABLE / 2 * nbUser * this->width / WIDTH_PIECES;
	int posY = this->height / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * (2 * nbUser / NB_USER_DISPLAYABLE) * this->height / HEIGHT_PIECES;
	int sizeX = this->width * 3 / WIDTH_PIECES;
	int sizeY = this->height * 3 / HEIGHT_PIECES;

	this->addUserButton->setGeometry(0, 0, 50, 50);

	connect(this->addUserButton, SIGNAL(released()), this, SLOT(on_addButton_clicked()));
}

void UserList::on_interfaceButton_clicked(int numUser)
{
	interface = new Interface();
	interface->InitInterface(this->user[numUser]);
	interface->show();
}

void UserList::on_editButton_clicked(int numUser)
{
	userEdits = new EditUser(this->user[numUser]);
	userEdits->InitInterface(this->query);
	userEdits->show();
}

void UserList::on_addButton_clicked()
{
	addUser = new AddUser(this->database, this->query);
	addUser->show();
}
