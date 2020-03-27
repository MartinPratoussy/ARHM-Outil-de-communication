#include "pictogram.h"

Pictogram::Pictogram(QString definition, QPixmap picture, Sound sound, QString category)
{
    this->definition = definition;
    this->picture = picture;
    this->sound = sound;
    this->category = category;
}

QString Pictogram::getDefinition()
{
    return this->definition;
}

QPixmap Pictogram::getPicture()
{
    return this->picture;
}

Sound Pictogram::getSound()
{
    return this->sound;
}

QString Pictogram::getCategory()
{
	return this->category;
}
