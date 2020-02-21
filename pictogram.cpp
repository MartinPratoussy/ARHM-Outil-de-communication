#include "pictogram.h"

Pictogram::Pictogram(QString definition, QPixmap picture, Sound sound)
{
    this->definition = definition;
    this->picture = picture;
    this->sound = sound;
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
