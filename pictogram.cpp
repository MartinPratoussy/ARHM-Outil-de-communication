#include "pictogram.h"

Pictogram::Pictogram()
{

}

Pictogram::Pictogram(QString definition, QPixmap image)
{
    this->definition = definition;
    this->image = image;
}
