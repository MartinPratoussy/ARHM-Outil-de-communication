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

void Sound::Say(QString text)
{
    this->speech->setLocale(QLocale());
    this->speech->setPitch(0.2);
    this->speech->setRate(-0.2);
    this->speech->Say(text);
}

void Sound::Play(QString text)
{
    switch (this->isSynthetic)
    {
    case true: this->Say(text); break;
    case false: this->sound->Play(); break;
    }
}
