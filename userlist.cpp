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

	// Génère un objet query qui contiendra les prochaines requêtes
	query = new QSqlQuery(*database);
}

void UserList::LoadUsers()
{
	// Récupère les utilisateurs dans la base de données
	if (!query->exec("SELECT idUser FROM \"User\" ORDER BY firstname")) qWarning() << "ERROR: idUser not found";

	this->nbUser = 0;
	this->usersId.clear();
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
	QString firstname, lastname, birthDate, handicap, urlPhoto;
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
		if (!query->exec("SELECT urlPhoto FROM \"User\" WHERE idUser = " + QString::number(id) + ";")) qWarning() << "ERROR: photo for user" + QString::number(id) + "not found";
		while (query->next()) urlPhoto = query->value(0).toString();
		qDebug() << "urlPhoto = " << urlPhoto;
		QIcon* photo = new QIcon(urlPhoto);
		this->user[numUser] = new User(id, firstname, lastname, birthDate, photo, database, query);
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
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
	// Positions et tailles des boutons
	int posX, posY, sizeX, sizeY;

	// Numéro de l'utilisateur
	int numUser = 0;

	// Place chacun des boutons de l'interface
	for (int numUserY = 0; numUserY < 2 * nbUser / NB_USER_DISPLAYABLE; numUserY++)
	{
		for (int numUserX = 0; numUserX < NB_USER_DISPLAYABLE / 2; numUserX++)
		{
			numUser = numUserX + (NB_USER_DISPLAYABLE / 2) * numUserY;

			// Crée les boutons d'accès aux interfaces utilisateurs
			interfaceButton[numUser] = new QPushButton(content);
			// Crée les boutons d'accès aux interfaces d'édition
			editButton[numUser] = new QPushButton(content);

			// Position et taille des boutons d'accès aux interfaces utilisateur
			posX = this->width / WIDTH_PIECES + (NB_USER_DISPLAYABLE / 2) * numUserX * this->width / WIDTH_PIECES;
			posY = this->height / HEIGHT_PIECES + (NB_USER_DISPLAYABLE / 2) * numUserY * this->height / HEIGHT_PIECES;
			sizeX = this->width * 3 / WIDTH_PIECES;
			sizeY = this->height * 3 / HEIGHT_PIECES;

			// Place les boutons d'accès aux interfaces utilisateurs
			this->interfaceButton[numUser]->setGeometry(posX, posY, sizeX, sizeY);

			// Place les boutons d'accès aux interfaces utilisateurs
			this->editButton[numUser]->setGeometry(
				posX + this->width / WIDTH_PIECES,
				posY + this->height * 3 / HEIGHT_PIECES,
				this->width / (WIDTH_PIECES + 1),
				this->height / (WIDTH_PIECES + 1));

			// Affiche le texte du bouton
			QFont font("MS Shell Dlg 2", 24);
			this->interfaceButton[numUser]->setFont(font);
			this->interfaceButton[numUser]->setText(
				this->user[numUser]->GetFirstname()
				+ " "
				+ this->user[numUser]->GetLastname());

			// Affichage de la photo de l'utilisateur
			this->interfaceButton[numUser]->setIcon(*this->user[numUser]->GetPhoto());
			QSize interfaceiconsize(128, 128);
			this->interfaceButton[numUser]->setIconSize(interfaceiconsize);

			// Affichage de l'icône d'édition
			QIcon editIcon("./data/edit.png");
			QSize editiconsize(32, 32);
			this->editButton[numUser]->setIcon(editIcon);
			this->editButton[numUser]->setIconSize(editiconsize);

			// Affiche les boutons
			this->interfaceButton[numUser]->show();
			this->editButton[numUser]->show();

			// Attribue aux boutons des slots paramétrés de la classse
			connect(this->interfaceButton[numUser], &QPushButton::released, [=] {
				on_interfaceButton_clicked(numUser);
			});

			connect(this->editButton[numUser], &QPushButton::released, [=] {
				on_editButton_clicked(numUser);
			});
		}
	}

	// Place les boutons qui n'ont pas été placés dans la boucle for précédente
	for (int i = 0; i < nbUser % (NB_USER_DISPLAYABLE / 2); i++)
	{
		// Calcul le numéro de l'utilisateur
		numUser = i + (nbUser / (NB_USER_DISPLAYABLE / 2)) * (NB_USER_DISPLAYABLE / 2);

		// Crée les boutons d'accès aux interfaces utilisateurs
		interfaceButton[numUser] = new QPushButton(content);
		// Crée les boutons d'accès aux interfaces d'édition
		editButton[numUser] = new QPushButton(content);

		posX = this->width / WIDTH_PIECES + (NB_USER_DISPLAYABLE / 2) * i * this->width / WIDTH_PIECES;
		posY = this->height / HEIGHT_PIECES + (NB_USER_DISPLAYABLE / 2) * (2 * nbUser / NB_USER_DISPLAYABLE) * (this->height / HEIGHT_PIECES);
		sizeX = this->width * 3 / WIDTH_PIECES;
		sizeY = this->height * 3 / HEIGHT_PIECES;

		this->interfaceButton[numUser]->setGeometry(posX, posY, sizeX, sizeY);
		this->editButton[numUser]->setGeometry(
			posX + this->width / WIDTH_PIECES,
			posY + this->height * 3 / HEIGHT_PIECES,
			this->width / (WIDTH_PIECES + 1),
			this->height / (WIDTH_PIECES + 1));

		// Affiche le texte du bouton
		QFont font("MS Shell Dlg 2", 24);
		this->interfaceButton[numUser]->setFont(font);
		this->interfaceButton[numUser]->setText(
			this->user[numUser]->GetFirstname()
			+ " "
			+ this->user[numUser]->GetLastname());

		// Affichage de la photo de l'utilisateur
		this->interfaceButton[numUser]->setIcon(*this->user[numUser]->GetPhoto());
		QSize interfaceiconsize(128, 128);
		this->interfaceButton[numUser]->setIconSize(interfaceiconsize);

		// Affichage de l'icône d'édition
		QIcon editIcon("./data/edit.png");
		QSize editiconsize(32, 32);
		this->editButton[numUser]->setIcon(editIcon);
		this->editButton[numUser]->setIconSize(editiconsize);

		// Affiche les boutons
		this->interfaceButton[numUser]->show();
		this->editButton[numUser]->show();

		// Attribue aux boutons des slots paramétrés de la classse
		connect(interfaceButton[numUser], &QPushButton::released, [=] {
			on_interfaceButton_clicked(numUser);
		});

		connect(editButton[numUser], &QPushButton::released, [=] {
			on_editButton_clicked(numUser);
		});
	}

	// Création du bouton d'ajout d'utilisateur
	addUserButton = new QPushButton(content);

	// Icône du bouton d'ajout d'utilisateur
	QIcon addUserIcon("./data/addusericon.png");
	QSize addiconsize(128, 128);
	this->addUserButton->setIcon(addUserIcon);
	this->addUserButton->setIconSize(addiconsize);
	
	// Placement du bouton d'ajout d'utilisateur
	if (nbUser % (NB_USER_DISPLAYABLE / 2) == 0)
	{
		posX = this->width / WIDTH_PIECES;
		posY = (nbUser / (NB_USER_DISPLAYABLE / 2)) * (this->height / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * this->height / HEIGHT_PIECES);
		sizeX = this->width * 3 / WIDTH_PIECES;
		sizeY = this->height * 3 / HEIGHT_PIECES;
	}

	else
	{
		posX = this->width / WIDTH_PIECES + (NB_USER_DISPLAYABLE / 2) * (nbUser % (NB_USER_DISPLAYABLE / 2)) * this->width / WIDTH_PIECES;
		posY = this->height / HEIGHT_PIECES + NB_USER_DISPLAYABLE / 2 * (2 * nbUser / NB_USER_DISPLAYABLE) * this->height / HEIGHT_PIECES;
		sizeX = this->width * 3 / WIDTH_PIECES;
		sizeY = this->height * 3 / HEIGHT_PIECES;
	}

	this->addUserButton->setGeometry(posX, posY, sizeX, sizeY);

	connect(this->addUserButton, SIGNAL(released()), this, SLOT(on_addButton_clicked()));

	this->addUserButton->show();
}

void UserList::UpdateUserlist() 
{
	LoadUsers();
	SetDisplayGeometry();
	ShowUserList();
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
	connect(this->userEdits, &EditUser::UpdateUsers, [=] {
		UpdateUserlist();
	});
	userEdits->show();
}

void UserList::on_addButton_clicked()
{
	addUser = new AddUser(this->database, this->query);
	connect(this->addUser, &AddUser::UpdateUsers, [=] {
		UpdateUserlist();
	});
	addUser->show();
}
