#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::UserList)
{
	ui->setupUi(this);

	qDebug() << this->geometry().height();

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
	//ui->scrollArea->setGeometry(0, 0, this->width, this->height + this->height * (1 / NB_USER_DISPLAYABLE) * nbUser);

	/*ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	ui->scrollArea->setSizeAdjustPolicy(QScrollArea::AdjustToContents);
	QLabel* imageLabel = new QLabel;
	QImage image("data/arhm.png");
	imageLabel->setPixmap(QPixmap::fromImage(image));

	ui->scrollArea->setBackgroundRole(QPalette::Dark);
	ui->scrollArea->setWidget(imageLabel);*/
	//ui->scrollArea->show();
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

			// Attribue aux boutons des méthodes de la classse
			connect(interfaceButton[numUserX + numUserY], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(/*this, numUserX + numUserY*/)));
			connect(editButton[numUserX + numUserY], SIGNAL(released()), this, SLOT(on_addButton_clicked(/*this, */numUserX + numUserY)));
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

		connect(interfaceButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], SIGNAL(released()), this, SLOT(on_interfaceButton_clicked(this, (2 * nbUser / NB_USER_DISPLAYABLE) + numUser, )));
		connect(editButton[(2 * nbUser / NB_USER_DISPLAYABLE) + numUser], SIGNAL(released()), this, SLOT(on_editButton_clicked(this, (2 * nbUser / NB_USER_DISPLAYABLE) + numUser)));
	}
	// Ajoute le bouton d'ajout d'utilisateur après le dernier utilisateur ajouté
	this->addUserButton = new QPushButton(ui->scrollArea);
	this->addUserButton->setGeometry(
		this->geometry().width() / WIDTH_PIECES + nbUser * (2 / NB_USER_DISPLAYABLE) * this->geometry().width() / WIDTH_PIECES,
		(nbUser + 1) * (this->geometry().height() / HEIGHT_PIECES + nbUser * (2 / NB_USER_DISPLAYABLE) * this->geometry().height() / HEIGHT_PIECES),
		this->geometry().width() * 3 / WIDTH_PIECES,
		this->geometry().height() / 3);
	this->addUserButton->show();
	connect(addUserButton, SIGNAL(released()), this, SLOT(on_addButton_clicked(/*this*/)));
}

void UserList::on_interfaceButton_clicked(/*UserList* userList, int numUser*/)
{
	interface = new Interface();
	interface->InitInterface(user[0]);
	interface->show();
}

void UserList::on_editButton_clicked(/*UserList* userList, int numUser*/)
{
	userEdits = new EditUser(user[0]);
	userEdits->InitInterface(this->query);
	userEdits->show();
}

void UserList::on_addButton_clicked(/*UserList* userList*/)
{
	addUser = new AddUser(this->database, this->query);
	addUser->show();
}
