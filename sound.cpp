#include "sound.h"

Sound::Sound()
{
}

Sound::Sound(QString urlSound)
{
    sound = new QMediaPlayer;
    sound->setMedia(QUrl::fromLocalFile(urlSound));
}

Sound::~Sound()
{
}

void Sound::say(QString text)
{
    this->speech->setLocale(QLocale());
    this->speech->setPitch(0.2);
    this->speech->setRate(-0.2);
    this->speech->say(text);
}

void Sound::play(QString text)
{
    switch (this->isSynthetic)
    {
    case true: this->say(text); break;
    case false: this->sound->play(); break;
    }
}
