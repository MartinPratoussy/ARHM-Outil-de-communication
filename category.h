#pragma once

#include "pictogram.h"

class Category
{
private:
    // Num�ro de la cat�gorie
    int id;
    int nbPicto;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    Category(int id, int nbPicto);
    ~Category();

    // Getters des attributs priv�s
    int GetId();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs priv�s
    void SetNbPicto(int value);
};
