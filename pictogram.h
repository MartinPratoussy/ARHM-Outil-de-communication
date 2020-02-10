#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#include <QtTextToSpeech/QTextToSpeech>
#include <QPixmap>

#include "sound.h"


class Pictogram
{
private:
    // Définition qui sera affichée et lue par la synthèse vocale
    QString definition;
    // Image Makaton du pictogramme
    QPixmap image;
    // Son à jouer lors de l'appui sur le bouton
    Sound sound;

public:
    Pictogram();
    Pictogram(QString definition, QPixmap image);
    ~Pictogram();

    // Récupère les attributs privés
    QString getDefinition();
};

#endif // PICTOGRAM_H
