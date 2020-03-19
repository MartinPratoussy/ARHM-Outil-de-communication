#ifndef USER_H
#define USER_H

#define NB_MAX_PICTO 100

// Format de chaîne de caractère de Qt
#include <QString>
// Format de date de Qt
#include <QDate>
// Contrôle les flux d'entrée/sortie
#include <iostream>

// Permet de charger une base de données
#include <QSqlDatabase>
// Permet d'accéder à des bases de données spécifiques
#include <QSqlDriver>
// Permet de générer une erreur lors d'un problème dans la base de donnnées
#include <QSqlError>
// Permet de généerer des requêtes SQL en direction d'une base de données
#include <QSqlQuery>

#include "pictogram.h"

class User
{
private:
    // Attributs de l'utlisateur
    QString firstname;
    QString lastname;
    QString birthDate;
    QString handicap;

    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    //Pictogram pictos[4][NB_MAX_PICTO];

public:
    User();
    User(QString firstname, QString lastname, QString birthDate, QString handicap);

    // Getters des attributs privés
    QString getFirstname();
    QString getLastname();
    QString getBirthDate();
    QString getHandicap();

    // Setters des attributs privés
    void setFirstname(QString firstname, QSqlQuery * query);
    void setLastname(QString lastname, QSqlQuery * query);
    void setBirthDate(QString birthDate, QSqlQuery * query);
    void setHandicap(QString handicap, QSqlQuery * query);

    // Edition de la base de données
    void query(QString value, QString row);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);
};

#endif // USER_H
