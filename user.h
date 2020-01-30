#ifndef USER_H
#define USER_H

#define NB_MAX_USER 100

#include "interface.h"

// Classe représentant un utlisateur de l'application
class User
{
private:
    // Attributs de l'utlisateur
    QString firstname;
    QString lastname;
    QDate birthDate;
    QString handicap;
    // Interface personnalisée de l'utilisateur
    Interface interface;


public:
    User();
    User(QString firstname, QString lastname, QDate birthDate, QString handicap, Interface interface);

    // Nombre d'utilisateurs enregistrés dans l'application
    static int nbUser;

    // Getters des attributs privés
    QString getFirstname();
    QString getLastname();
    QDate getBirthDate();
    QString getHandicap();
    Interface getInterface();

    // Setters des attributs privés
    void setFirstname(QString firstname);
    void setLastname(QString lastname);
    void setBirthDate(QDate birthDate);
    void setHandicap(QString handicap);
    void setInterface(Interface interface);

    // Edition de la base de données
    void query(QString value);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);

};

#endif // USER_H
