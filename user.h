#ifndef USER_H
#define USER_H

#define NB_MAX_PICTO 100

#include <QString>
#include <QDate>

#include "database.h"
#include "pictogram.h"

class User
{
private:
    // Attributs de l'utlisateur
    QString firstname;
    QString lastname;
    QDate birthDate;
    QString handicap;

    // Tableau contenant les pictogrammes que l'utilisateur peut utiliser
    //Pictogram pictos[4][NB_MAX_PICTO];

public:
    User();
    User(QString firstname, QString lastname, QDate birthDate, QString handicap);

    // Getters des attributs privés
    QString getFirstname();
    QString getLastname();
    QDate getBirthDate();
    QString getHandicap();

    // Setters des attributs privés
    void setFirstname(QString firstname);
    void setLastname(QString lastname);
    void setBirthDate(QDate birthDate);
    void setHandicap(QString handicap);

    // Edition de la base de données
    void query(QString value);

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);
};

#endif // USER_H
