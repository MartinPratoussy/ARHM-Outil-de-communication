#ifndef USER_H
#define USER_H

#define NB_MAX_PICTO 100

// Format de chaîne de caractère de Qt
#include <QString>
// Format de date de Qt
#include <QDate>
// Format d'image pour les boutons
#include <QIcon>

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
    Category category[4];

    // Photo de l'utilisateur
    QIcon* photo;

public:
    User();
    User(int id, QString firstname, QString lastname, QString birthDate, QIcon* photo, QSqlDatabase* database, QSqlQuery* query);
    ~User();

    // Getters des attributs privés
    int GetId();
    QString GetFirstname();
    QString GetLastname();
    QString GetBirthDate();
    Category* GetCategory();
    QIcon* GetPhoto();

    // Setters des attributs privés
    void SetFirstname(QString firstname, QSqlQuery* query);
    void SetLastname(QString lastname, QSqlQuery* query);
    void SetBirthDate(QString birthDate, QSqlQuery* query);
    void SetCategory(QString* category, QSqlQuery* query);
    void SetPhoto(QString urlPhoto, QSqlQuery* query);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);
};

#endif // USER_H
