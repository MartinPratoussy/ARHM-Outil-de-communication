#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#include <QWidget>
#include <iostream>
#include <QtTextToSpeech/QTextToSpeech>
#include <QPixmap>

// Pictogrammes sur lesquels l'utlisateur devra appuyer pour construire ses phrases (unb texte, un son et une image seront liés à chaque élément)
namespace Ui {
class  Pictogram;
}

class Pictogram : public QWidget
{
    Q_OBJECT
private:
    Ui::Pictogram *ui;

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
