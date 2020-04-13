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
    void Say(QString text);

    // Joue le son non synthétisé
    void Play(QString text);

private:
    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech;

    QMediaPlayer * sound;

    // Détermine si le son est produit par la synthèse vocale ou s'il existe déjà dans la base de données
    bool isSynthetic;
};

#endif SOUND_H
