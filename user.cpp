#include "user.h"

User::User(int id, QString firstname, QString lastname, QString birthDate, QSqlDatabase* database, QSqlQuery* query)
{
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthDate = birthDate;

	InitiateUser(database, query);

	// Initialisation des catégories
	int numCategory = 0;
	while (query->next()) {
		this->category[numCategory]->SetId(query->value(0).toInt());
		this->category[numCategory]->SetText(query->value(1 + 1).toString());
		InitiateCategory(this->category[numCategory], database, query);
		numCategory++;
	}

}

void User::InitiateUser(QSqlDatabase* database, QSqlQuery* query)
{
	if (!query->exec("SELECT Category.id, Category.text FROM Category, User, Category_User WHERE Category_User.category = Category.id AND Category_User.user = User.id AND User.id = " + QString::number(this->id) + ";")
		)qWarning() << "ERROR: no category found";
}

void User::InitiateCategory(Category * category, QSqlDatabase* database, QSqlQuery* query)
{
	QList<int> values;
	// Selectionne tous les pictogrammes de l'utilisateur dans la base de données
	if (!query->exec("SELECT Pictogram.id FROM \"Pictogram\", \"Category\", \"Pictogram_Category\" WHERE Pictogram_Category.pictogram = Pictogram.id AND Pictogram_Category.category = Category.id AND Pictogram_Category.category = " + QString::number(category->GetId()) + ";")
		) qWarning() << "ERROR: no pictogram found for category" + category->GetText();

	// Tant qu'il y a des pictogrammes, le nombre de pictogramme s'incrémente
	while (query->next())
	{
		category->SetNbPicto(category->GetNbPicto() + 1);
		values.append(query->value(0).toInt());
	}

	// Création des pictogrammes dans le code
	QString definition, urlImage, urlSound;

	for each (int value in values)
	{
		// Requêtes SQL récupérant les trois attributs d'un pictogramme selon l'utlisateur qui le possède
		if (!query->exec(
			"SELECT definition FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no definiton found for pictogram" + value;
		while (query->next()) definition = query->value(0).toString();
		if (!query->exec(
			"SELECT urlImage FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no urlImage found for pictogram" + value;
		while (query->next()) urlImage = query->value(0).toString();
		if (!query->exec(
			"SELECT urlSound FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no urlSound found for pictogram" + value;
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

Category* User::GetCategory()
{
	return *this->category;
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
	for (int i = 0; i < 4; i++) this->category[i]->SetText(category[i]);
	// La modification est aussi apportée à la base de données
	for each (Category* category in this->category) {
		if (!query->exec("UPDATE Category SET text = '" + category->GetText() + "' WHERE idCategory = '" + category->GetId() + "';")) qWarning() << "ERROR : Set category for user id = " + this->id;
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
