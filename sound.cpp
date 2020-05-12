#include "sound.h"

Sound::Sound()
{
}

Sound::Sound(QString definition)
{
    this->definition = definition;
}

Sound::Sound(QString definition, QString urlSound)
{
    this->definition = definition;
    this->isSynthetic = false;
    sound = new QMediaPlayer;
    sound->setMedia(QUrl::fromLocalFile(urlSound));
}

Sound::~Sound()
{
}

void Sound::PlaySound()
{
    switch (this->isSynthetic)
    {
    case true: this->SyntheticSay(); break;
    case false: this->sound->play(); break;
    default: this->SyntheticSay(); break;
    }
}

void Sound::SyntheticSay()
{
    this->speech->setLocale(QLocale());
    this->speech->setPitch(0.2);
    this->speech->setRate(-0.2);
    this->speech->say(this->definition);
}