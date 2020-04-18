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

#include "category.h"

class User
{
private:
    // Attributs de l'utlisateur
    int id;
    QString firstname;
    QString lastname;
    QString birthDate;

    // Catégories de boutons
    Category* category[4];

    // Méthodes de factorisation du constructeur
    void InitiateUser(QSqlDatabase* database, QSqlQuery* query);
    void InitiateCategory(Category * category, QSqlDatabase* database, QSqlQuery* query);

public:
    User();
    User(int id, QString firstname, QString lastname, QString birthDate, QSqlDatabase* database, QSqlQuery* query);
    ~User();

    // Getters des attributs privés
    int GetId();
    QString GetFirstname();
    QString GetLastname();
    QString GetBirthDate();
    Category* GetCategory();

    // Setters des attributs privés
    void SetFirstname(QString firstname, QSqlQuery * query);
    void SetLastname(QString lastname, QSqlQuery * query);
    void SetBirthDate(QString birthDate, QSqlQuery * query);
    void SetCategory(QString* category, QSqlQuery* query);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);
};

#endif // USER_H
