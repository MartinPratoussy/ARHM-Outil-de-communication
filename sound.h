#ifndef SOUND_H
#define SOUND_H

#include <QtTextToSpeech/QTextToSpeech>
#include <QMediaPlayer>

class Sound
{
public:
    Sound();

    // Synthèse vocale
    void say(QString text);
    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech;
};

#endif // SOUND_H
