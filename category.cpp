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

int Category::GetNbPicto()
{
	return nbPicto;
}

QList<Pictogram*> Category::GetPicto()
{
	return this->pictos;
}

void Category::SetNbPicto(int value)
{
	this->nbPicto = value;
}
