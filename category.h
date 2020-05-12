#pragma once

// Contr�le les flux d'entr�e/sortie
#include <iostream>
// Permet d'acc�der � des bases de donn�es sp�cifiques
#include <QSqlDriver>
// Permet de charger une base de donn�es
#include <QSqlDatabase>
// Permet de g�n�rer des requ�tes SQL en direction d'une base de donn�es
#include <QSqlQuery>
// Permet de g�n�rer une erreur lors d'un probl�me dans la base de donnn�es
#include <QSqlError>

#include "pictogram.h"

class Category
{
private:
    // Num�ro de la cat�gorie
    int id = 0;

    // Nom de la cat�gorie
    QString text = nullptr;

    // Nombre de pictogrammes dans la cat�gorie
    int nbPicto = 0;
    
    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

public:
    Category();
    ~Category();

    // Getters des attributs priv�s
    int GetId();
    QString GetText();
    int GetNbPicto();
    QList<Pictogram*> GetPicto();

    // Setters des attributs priv�s
    void InitiateCategory(QSqlQuery* query, int id, QString text);
    void SetId(int value);
    void SetText(QString text);
    void SetNbPicto(int value);
};
