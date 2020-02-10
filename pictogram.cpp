#include "pictogram.h"

Pictogram::Pictogram(QString definition, QPixmap image)
{
    this->definition = definition;
    this->image = image;
}

QString Pictogram::getDefinition()
{
    return this->definition;
}
