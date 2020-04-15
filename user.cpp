#include "user.h"

User::User(int id, QString firstname, QString lastname, QString birthDate, QSqlDatabase* database, QSqlQuery* query)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthDate = birthDate;

	InitiateUser(database, query);

	// Initialisation des catégories
	int numCategory = 0;
	while (query->next()) {
		this->category[numCategory].SetId(query->value(numCategory).toInt());
		this->category[numCategory].SetText(query->value(numCategory + 1).toString());
		numCategory += 2;
	}
}

void User::InitiateUser(QSqlDatabase* database, QSqlQuery* query)
{
	// Ajout des attributs dans la table User de a base de données
	if (!query->exec("INSERT INTO user VALUES ('"
		+ this->firstname + "', '"
		+ this->lastname + "', '"
		+ this->birthDate + ")"))
		qWarning() << "ERROR: " << query->lastError().text();

	if (!query->exec("SELECT Category.id, Category.text FROM Category, User, Category_User WHERE Category_User.category = Category.id AND Category_User.user = User.id AND User.id = " + this->id)
		)qWarning() << "ERROR: " << database->lastError().text();
}

void User::InitiateCategory(Category * category, QSqlDatabase* database, QSqlQuery* query)
{
	QList<int> values;
	// Selectionne tous les pictogrammes de l'utilisateur dans la base de données
	if (!query->exec("SELECT Pictogram.id FROM \"Pictogram\", \"Category\", \"Pictogram_Category\" WHERE Pictogram_Category.pictogram = Pictogram.id AND Pictogram_Category.category = Category.id AND Pictogram_Category.category = " + category->GetId())
		) qWarning() << "ERROR: " << database->lastError().text();

	// Tant qu'il y a des pictogrammes, le nombre de pictogramme s'incrémente
	while (query->next())
	{
		category->SetNbPicto(category->GetNbPicto() + 1);
		values.append(query->value(category->GetNbPicto()).toInt());
	}

	// Création des pictogrammes dans le code
	QString definition, urlImage, urlSound;

	for each (int value in values)
	{
		// Requêtes SQL récupérant les trois attributs d'un pictogramme selon l'utlisateur qui le possède
		if (!query->exec(
			"SELECT definition FROM \"Pictogram\" WHERE idPictogram = " + value)
			) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) definition = query->value(0).toString();
		if (!query->exec(
			"SELECT urlImage FROM \"Pictogram\" WHERE idPictogram = " + value)
			) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) urlImage = query->value(0).toString();
		if (!query->exec(
			"SELECT urlSound FROM \"Pictogram\" WHERE idPictogram = " + value)
			) qWarning() << "ERROR: " << database->lastError().text();
		while (query->next()) urlSound = query->value(0).toString();

		//Conversion des QString en QPixmap et en Sound
		QPixmap image(urlImage);
		Sound sound(definition, urlSound);

		// Création de l'objet Pictogram
		category->GetPicto().append(new Pictogram(definition, image, sound));
	}
}


User::~User()
{
}

int User::GetId()
{
	return this->id;
}

QString User::GetFirstname()
{
	return this->firstname;
}

QString User::GetLastname()
{
	return this->lastname;
}

QString User::GetBirthDate()
{
	return this->birthDate;
}

Category * User::GetCategory()
{
	return this->category;
}

void User::SetFirstname(QString firstname, QSqlQuery* query)
{
	this->firstname = firstname;
	if (!query->exec("UPDATE user SET firstname = '" + this->firstname + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::SetLastname(QString lastname, QSqlQuery* query)
{
	this->lastname = lastname;
	if (!query->exec("UPDATE user SET lastname = '" + this->lastname + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::SetBirthDate(QString birthDate, QSqlQuery* query)
{
	this->birthDate = birthDate;
	if (!query->exec("UPDATE user SET birthDate = '" + this->birthDate + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::SetCategory(QString* category, QSqlQuery* query)
{
	for (int i = 0; i < 4; i++) this->category[i].SetText(category[i]);
	for each (Category category in this->category) {
		if (!query->exec("UPDATE Category SET text = " + category.GetText() + "WHERE idCategory = " + category.GetId() + "")) qWarning() << "ERROR : " << query->lastError().text();
	}
}

User& User::operator=(const User& user)
{
	this->firstname = user.firstname;
	this->lastname = user.lastname;
	this->birthDate = user.birthDate;
	*this->category = *user.category;

	return *this;
}
