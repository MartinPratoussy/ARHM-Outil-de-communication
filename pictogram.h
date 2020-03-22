#ifndef PICTOGRAM_H
#define PICTOGRAM_H

// Permet de charger des images
#include <QPixmap>

#include "sound.h"

class Pictogram
{
private:
    // Définition qui sera affichée et lue par la synthèse vocale
    QString definition;

    // Image Makaton du pictogramme
    QPixmap picture;

    // Son à jouer lors de l'appui sur le bouton
    Sound sound;

public:
    Pictogram();

    Pictogram(QString definition, QPixmap picture, Sound sound);

    ~Pictogram();

    // Getters des attributs privés
    QString getDefinition();
    QPixmap getPicture();
    Sound getSound();
};

#endif // PICTOGRAM_H
