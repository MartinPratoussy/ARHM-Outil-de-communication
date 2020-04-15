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
    Sound(QString definition);
    Sound(QString definition, QString urlSound);
    ~Sound();

    // Joue le son du pictogramme
    void PlaySound();

private:
    // Texte du pictogramme à lire
    QString definition;

    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech;

    QMediaPlayer * sound;

    // Détermine si le son est produit par la synthèse vocale ou s'il existe déjà dans la base de données
    bool isSynthetic = false;

    // Synthèse vocale
    void SyntheticSay();
};

#endif SOUND_H
