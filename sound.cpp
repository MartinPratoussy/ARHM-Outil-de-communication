#include "sound.h"

Sound::Sound()
{
}

void Sound::say(QString text)
{
    this->speech->setLocale(QLocale());
    this->speech->setPitch(0.2);
    this->speech->setRate(-0.2);
    this->speech->say(text);
}
