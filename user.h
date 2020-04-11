#ifndef USER_H
#define USER_H

#define NB_MAX_PICTO 100

// Format de chaîne de caractère de Qt
#include <QString>
// Format de date de Qt
#include <QDate>
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

class User
{
private:
    // Attributs de l'utlisateur
    int id;
    QString firstname;
    QString lastname;
    QString birthDate;

    // Nombre de pictogrammes que l'utilisateur possède
    int nbPicto;

    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    QList<Pictogram*> pictos;

    // Catégories de boutons
    QString category[4];

public:
    User();
    User(int id, QString firstname, QString lastname, QString birthDate, QSqlDatabase* database, QSqlQuery* query);
    ~User();

    // Getters des attributs privés
    int getId();
    QString getFirstname();
    QString getLastname();
    QString getBirthDate();
    int getNbPicto();
    QList<Pictogram*> getPicto();
    QString getCategory(int i);

    // Setters des attributs privés
    void setFirstname(QString firstname, QSqlQuery * query);
    void setLastname(QString lastname, QSqlQuery * query);
    void setBirthDate(QString birthDate, QSqlQuery * query);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);
};

#endif // USER_H
