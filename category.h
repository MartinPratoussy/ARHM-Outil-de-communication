#pragma once

#include "pictogram.h"

class Category
{
private:
    // Numéro de la catégorie
    int id;

    // Nom de la catégorie
    QString text;

    // Nombre de pictogrammes dans la catégorie
    int nbPicto;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    Category(int id, int nbPicto);
    ~Category();

    // Getters des attributs privés
    int GetId();
    QString GetText();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs privés
    void SetId(int value);
    void SetText(QString text);
    void SetNbPicto(int value);
};
