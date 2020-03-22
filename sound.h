#ifndef SOUND_H
#define SOUND_H

// Synthèse vocale
#include <QtTextToSpeech/QTextToSpeech>
// Permet de lire des médias
#include <QMediaPlayer>

class Sound
{
public:
    Sound();
    Sound(QString urlSound);

    ~Sound();

    // Synthèse vocale
    void say(QString text);

    // Joue le son non synthétisé
    void play();

    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech;

    QMediaPlayer* sound;
};

#endif // SOUND_H
