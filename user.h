#ifndef USER_H
#define USER_H

#include <QDate>

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
    User(QString firstname, QString lastname, QDate birthDate, QString handicap);
    ~User();

    // Affiche l'interface personnalisée de l'utlisateur
    void DisplayInterface();
    // Edite les différents attributs de l'utlisateur
    void EditFirstname(QString firstname);
    void EditLastname(QString lastname);
    void EditBirthDate(QDate birthDate);
    void EditHandicap(QString handicap);
    // Supprime l'utilisateur
    void DeleteUser();
};

#endif // USER_H
