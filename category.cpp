#include "category.h"

Category::Category()
{

}

Category::Category(int id, int nbPicto)
{
	this->id = id;
	this->nbPicto = nbPicto;
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
	return this->text;;
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
