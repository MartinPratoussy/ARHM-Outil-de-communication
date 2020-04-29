#pragma once

// Contrôle les flux d'entrée/sortie
#include <iostream>
// Permet d'accéder à des bases de données spécifiques
#include <QSqlDriver>
// Permet de charger une base de données
#include <QSqlDatabase>
// Permet de générer des requêtes SQL en direction d'une base de données
#include <QSqlQuery>
// Permet de générer une erreur lors d'un problème dans la base de donnnées
#include <QSqlError>

#include "pictogram.h"

class Category
{
private:
    // Numéro de la catégorie
    int id = 0;

    // Nom de la catégorie
    QString text = nullptr;

    // Nombre de pictogrammes dans la catégorie
    int nbPicto = 0;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    ~Category();

    // Getters des attributs privés
    int GetId();
    QString GetText();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs privés
    void InitiateCategory(QSqlQuery* query, int id, QString text);
    void SetId(int value);
    void SetText(QString text);
    void SetNbPicto(int value);
};
