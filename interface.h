#ifndef INTERFACE_H
#define INTERFACE_H

#define NB_MAX_PICTO 100

#include "pictogram.h"

// Interface personnalisée en fonction des besoins de l'utlisateur
namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT
private:
    Ui::Interface *ui;

    // Tableau contenant les pictogrammes que l'interface affiche
    Pictogram * pictos[NB_MAX_PICTO];
    // Phrase créée par l'utilisateur
    QString * sentence[3];
    // Nombre d'étapes de la phrase effectuées
    int numLevel = 0;
    // Nombre de pictogrammes sur l'interface
    int nbPicto = 0;

public:
    explicit Interface(QWidget * parent = nullptr);
    ~Interface();

    // Annule l'action précédente
    void Cancel();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

signals:
    // Le signal est envoyé quand l'utlisateur clique sur l'image
    void pictoOnClicked(Pictogram pictogram);

};

#endif // INTERFACE_H
