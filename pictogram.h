#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#include <iostream>
#include <QtTextToSpeech/QTextToSpeech>
#include <QPixmap>

// Pictogrammes sur lesquels l'utlisateur devra appuyer pour construire ses phrases (unb texte, un son et une image seront liés à chaque élément)
class Pictogram
{
private:
    QString definition;
    QPixmap image;
    // Pointeur permettant de synthétiser vocalement la définition
    QTextToSpeech * speech = new QTextToSpeech();
public:
    Pictogram();
    Pictogram(QString definition, QPixmap image);
    ~Pictogram();

    // Récupère les attributs privés
    QString getDefinition();
    QTextToSpeech * getSpeech();
};

#endif // PICTOGRAM_H
