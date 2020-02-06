#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#include <QtTextToSpeech/QTextToSpeech>
#include <QPixmap>


class Pictogram
{
private:
    // Définition qui sera affichée et lue par la synthèse vocale
    QString definition;
    // Image Makaton du pictogramme
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
