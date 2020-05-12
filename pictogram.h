#ifndef PICTOGRAM_H
#define PICTOGRAM_H

// Format d'image pour les boutons
#include <QIcon>

#include "sound.h"

class Pictogram
{
private:
    // Définition qui sera affichée et lue par la synthèse vocale
    QString definition;

    // Image Makaton du pictogramme
    QIcon* picture;

    // Son à jouer lors de l'appui sur le bouton
    Sound* sound;

public:
    Pictogram();

    Pictogram(QString definition, QIcon* picture, Sound* sound);

    ~Pictogram();

    // Getters des attributs privés
    QString GetDefinition();
    QIcon* GetPicture();
    Sound* GetSound();
};

#endif // PICTOGRAM_H
