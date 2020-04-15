#pragma once

#include "pictogram.h"

class Category
{
private:
    // Num�ro de la cat�gorie
    int id;

    // Nom de la cat�gorie
    QString text;

    // Nombre de pictogrammes dans la cat�gorie
    int nbPicto;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    Category(int id, int nbPicto);
    ~Category();

    // Getters des attributs priv�s
    int GetId();
    QString GetText();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs priv�s
    void SetId(int value);
    void SetText(QString text);
    void SetNbPicto(int value);
};
