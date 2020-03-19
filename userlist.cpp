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
		while (query->next()) this->user[i]->setFirstname(query->value(0).toString(), query);
		if (!query->exec("SELECT lastname FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) this->user[i]->setLastname(query->value(0).toString(), query);
		if (!query->exec("SELECT birthdate FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) this->user[i]->setBirthDate(query->value(0).toString(), query);
		if (!query->exec("SELECT handicap FROM \"User\" WHERE id = " + QString::number(i))) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) this->user[i]->setHandicap(query->value(0).toString(), query);
	}

	nbUser = 10;
	user[0] = new User("test", "test", "test", "test");

#pragma endregion /*Récupère chaque utilisateur dans la base de données*/

#pragma region setDisplay
	// Initialisation de la taille de la fenêtre
	this->width = QApplication::desktop()->width();
	this->height = QApplication::desktop()->height();
	QApplication::desktop()->setGeometry(0, 0, this->width, this->height + this->height * (1 / 8) * nbUser);

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
	for (int numUserY = 0; numUserY < nbUser / 4; numUserY++) 
	{
		for (int numUserX = 0; numUserX < 4; numUserX++)
		{
			// Crée les boutons d'accès aux interfaces utilisateurs
			interfaceButton[numUserX + numUserX] = new QPushButton(this);
			// Crée les boutons d'accès aux interfaces d'édition
			editButton[numUserX + numUserX] = new QPushButton(this);

			int posX = this->width / 17 + 4 * numUserX * this->width / 17;
			int posY = this->height / 9 + 4 * numUserY * this->height / 9;
			int sizeX = this->width * 3 / 17;
			int sizeY = this->height * 3 / 9;

			// Place les boutons d'accès aux interfaces utilisateurs
			this->interfaceButton[numUserX + numUserX]->setGeometry(posX, posY, sizeX, sizeY);
			// Place les boutons d'accès aux interfaces utilisateurs
			/*this->editButton[numUser]->setGeometry(
				8 * this->width / 10,
				numUser * this->height / 10,
				this->width / 10,
				this->height / 10);*/
				// Affiche les boutons
			this->interfaceButton[numUserX + numUserX]->show();
			this->editButton[numUserX + numUserX]->show();

			connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_editButton_clicked(0)));
			connect(interfaceButton[numUserX + numUserX], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(numUserX + numUserX)));
			connect(editButton[numUserX + numUserX], SIGNAL(released()), this, SLOT(on_addButton_clicked(numUserX + numUserX)));
		}
	}
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
		//this->editButton[(nbUser / 4) + numUser]->setGeometry(posX, posY, sizeX, sizeY);

		connect(interfaceButton[(nbUser / 4) + numUser], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked((nbUser / 4) + numUser)));
		connect(editButton[(nbUser / 4) + numUser], SIGNAL(released()), this, SLOT(on_addButton_clicked((nbUser / 4) + numUser)));
	}
	// Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
	this->addUserButton = new QPushButton(this);
	this->addUserButton->setGeometry(
		this->width / 17 + nbUser * (1 / 4) * this->width / 17,
		(nbUser + 1) * (this->height / 9 + nbUser * (1 / 2) * this->height / 9),
		this->width * 3 / 17,
		this->height / 9);
	this->addUserButton->show();

#pragma endregion
}

void UserList::on_interfaceButton_clicked(int numUser)
{
	interface = new Interface();
	interface->InitInterface(user[numUser]);
	interface->show();
}

void UserList::on_editButton_clicked(int numUser)
{
	userEdits = new EditUser();
	userEdits->InitInterface(user[numUser], this->query);
	userEdits->show();
}

void UserList::on_addButton_clicked()
{
	addUser = new AddUser();
	addUser->show();
}
