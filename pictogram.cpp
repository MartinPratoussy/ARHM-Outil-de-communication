#include "pictogram.h"

Pictogram::Pictogram()
{
}

Pictogram::Pictogram(QString definition, QIcon* picture, Sound* sound)
{
    this->definition = definition;
    this->picture = picture;
    this->sound = sound;
}

Pictogram::~Pictogram()
{
}

QString Pictogram::GetDefinition()
{
    return this->definition;
}

QIcon* Pictogram::GetPicture()
{
    return this->picture;
}

Sound* Pictogram::GetSound()
{
    return this->sound;
}
