#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#define NB_MAX_PICTO 100

#include "includes.h"

#include "database.h"

class Pictogram
{
public:
    Pictogram();
    Pictogram(QString definition, QPixmap image);
    ~Pictogram();

    // Récupère les attributs privés
    QString getDefinition();
    QTextToSpeech * getSpeech();

private:
    // Définition qui sera affichée et lue par la synthèse vocale
    QString definition;
    // Image Makaton du pictogramme
    QPixmap image;
    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech();
};

#endif // PICTOGRAM_H
