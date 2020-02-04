#include "pictogram.h"

Pictogram::Pictogram(QString definition, QPixmap image)
{
    this->definition = definition;
    this->image = image;
}

Pictogram::~Pictogram()
{

}

QString Pictogram::getDefinition()
{
    return this->definition;
}

QTextToSpeech * Pictogram::getSpeech()
{
    return this->speech;
}

