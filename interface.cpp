#include "interface.h"

Interface::Interface()
{

}

void Interface::Cancel()
{
    sentence[numLevel] = "";
    numLevel--;
}

void Interface::pictoOnClicked(Pictogram pictogram)
{
    pictogram.getSpeech()->say(pictogram.getDefinition());
    this->sentence[numLevel] = pictogram.getDefinition();
    numLevel++;
}
