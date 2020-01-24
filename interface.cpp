#include "interface.h"

Interface::Interface()
{

}

void Interface::pictoOnClicked(Pictogram pictogram)
{
    pictogram.getSpeech()->say(pictogram.getDefinition());
    this->sentence += " " + pictogram.getDefinition();
}
