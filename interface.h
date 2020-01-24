#ifndef INTERFACE_H
#define INTERFACE_H

#define NB_MAX_PICTO 100

#include "pictogram.h"

// Interface personnalisée en fonction des besoins de l'utlisateur
class Interface
{
private:
    // Tableau contenant les pictogrammes que l'interface affiche
    Pictogram pictos[NB_MAX_PICTO];
    // Phrase créée par l'utilisateur
    QString sentence;
public:
    Interface();

signals:
    // Le signal est envoyé quand l'utlisateur clique sur l'image
    void pictoOnClicked(Pictogram pictogram);

};

#endif // INTERFACE_H
