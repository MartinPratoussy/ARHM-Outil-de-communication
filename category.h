#pragma once

#include "pictogram.h"

class Category
{
private:
    // Numéro de la catégorie
    int id;
    int nbPicto;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    Category(int id, int nbPicto);
    ~Category();

    // Getters des attributs privés
    int GetId();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs privés
    void SetNbPicto(int value);
};
