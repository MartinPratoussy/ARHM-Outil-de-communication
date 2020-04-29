#include "user.h"

User::User()
{
}

User::User(int id, QString firstname, QString lastname, QString birthDate, QIcon* photo, QSqlDatabase* database, QSqlQuery* query)
{
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthDate = birthDate;
	this->photo = photo;

	if (!query->exec("SELECT category.idCategory, category.text FROM Category, Category_User, User WHERE Category_User.category = category.idCategory AND Category_User.user = User.idUser AND User.idUser = "
		+ QString::number(this->id) + ";")
		) qWarning() << "ERROR: no category found";

	// Initialisation des catégories
	int value = 0;
	int idCategory[4];
	QString text[4];

	// Récupération des valeurs de la réponse
	while(query->next())
	{
		idCategory[value] = query->value("idCategory").toInt();
		text[value] = query->value("text").toString();
		value++;
	}

	// Création des catégories de l'utilisateur
	for (int i = 0; i < 4; i++)	this->category[i].InitiateCategory(query, idCategory[i], text[i]);
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

Category* User::GetCategory()
{
	return this->category;
}

QIcon* User::GetPhoto()
{
	return this->photo;
}

void User::SetFirstname(QString firstname, QSqlQuery* query)
{
	this->firstname = firstname;
	// La modification est aussi apportée à la base de données
	if (!query->exec("UPDATE user SET firstname = '" + this->firstname + "' WHERE idUser = '" + this->id + "';")) qWarning() << "ERROR : Set firstname for user id = " + this->id;
}

void User::SetLastname(QString lastname, QSqlQuery* query)
{
	this->lastname = lastname;
	// La modification est aussi apportée à la base de données
	if (!query->exec("UPDATE user SET lastname = '" + this->lastname + "' WHERE idUser = '" + this->id + "';")) qWarning() << "ERROR : Set lastname for user id = " + this->id;
}

void User::SetBirthDate(QString birthDate, QSqlQuery* query)
{
	this->birthDate = birthDate;
	// La modification est aussi apportée à la base de données
	if (!query->exec("UPDATE user SET birthDate = '" + this->birthDate + "' WHERE idUser = '" + this->id + "';")) qWarning() << "ERROR : Set birthdate for user id = " + this->id;
}

void User::SetCategory(QString* category, QSqlQuery* query)
{
	// Le texte des 4 catégories est changé
	for (int i = 0; i < 4; i++) this->category[i].SetText(category[i]);
	// La modification est aussi apportée à la base de données
	for each (Category category in this->category) {
		if (!query->exec("UPDATE Category SET text = '" + category.GetText() + "' WHERE idCategory = '" + category.GetId() + "';")) qWarning() << "ERROR : Set category for user id = " + this->id;
	}
}

void User::SetPhoto(QString urlPhoto, QSqlQuery* query)
{
	this->photo = new QIcon(urlPhoto);
	// La modification est aussi apportée à la base de données
	if (!query->exec("UPDATE user SET urlPhoto = '" + urlPhoto + "' WHERE idUser = '" + this->id + "';")) qWarning() << "ERROR : Set urlPhoto for user id = " + this->id;

}

User& User::operator=(const User& user)
{
	this->firstname = user.firstname;
	this->lastname = user.lastname;
	this->birthDate = user.birthDate;
	*this->category = *user.category;
	this->photo = user.photo;

	return *this;
}
