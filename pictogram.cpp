#include "pictogram.h"

Pictogram::Pictogram()
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
