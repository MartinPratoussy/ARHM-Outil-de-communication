#include "category.h"

Category::Category()
{

}

Category::Category(QSqlQuery* query, int id, QString text)
{
	this->id = id;
	this->text = text;

	// Selectionne tous les pictogrammes de l'utilisateur dans la base de données
	if (!query->exec("SELECT Pictogram.idPictogram FROM \"Pictogram\", \"Category\", \"Pictogram_Category\" WHERE Pictogram_Category.pictogram = Pictogram.idPictogram AND Pictogram_Category.category = Category.idCategory AND Pictogram_Category.category = " + QString::number(this->id)) + ";"
		) qWarning() << "ERROR: no pictogram found for category " + this->text;

	// Tant qu'il y a des pictogrammes, le nombre de pictogramme s'incrémente et leurs id sont récupérés
	QList<int> values;
	while (query->next())
	{
		this->SetNbPicto(this->nbPicto + 1);
		values.append(query->value(0).toInt());
	}

	// Création des pictogrammes dans le code
	QString definition, urlImage, urlSound;

	for each (int value in values)
	{
		// Requêtes SQL récupérant les trois attributs d'un pictogramme selon l'utlisateur qui le possède
		if (!query->exec(
			"SELECT definition FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no definiton found for pictogram " + value;
		while (query->next()) definition = query->value("definition").toString();
		if (!query->exec(
			"SELECT urlImage FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no urlImage found for pictogram " + value;
		while (query->next()) urlImage = query->value("urlImage").toString();
		if (!query->exec(
			"SELECT urlSound FROM \"Pictogram\" WHERE idPictogram = " + QString::number(value) + ";")
			) qWarning() << "ERROR: no urlSound found for pictogram " + value;
		while (query->next()) urlSound = query->value("urlSound").toString();

		//Conversion des QString en QPixmap et en Sound
		QPixmap image(urlImage);
		Sound sound(definition, urlSound);

		// Création de l'objet Pictogram
		this->pictos.append(new Pictogram(definition, image, sound));
	}
}

Category::~Category()
{
}

int Category::GetNbPicto()
{
	return this->nbPicto;
}

int Category::GetId()
{
	return this->id;
}

QString Category::GetText()
{
	return this->text;
}

QList<Pictogram*> Category::GetPicto()
{
	return this->pictos;
}

void Category::SetId(int value)
{
	this->id = value;
}

void Category::SetText(QString text)
{
	this->text = text;
}

void Category::SetNbPicto(int value)
{
	this->nbPicto = value;
}
