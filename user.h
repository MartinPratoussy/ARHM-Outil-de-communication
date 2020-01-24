#ifndef USER_H
#define USER_H

#include <QDate>

#include "interface.h"

// Classe représentant un utlisateur de l'application
class User
{
private:
    QString firstname;
    QString lastname;
    QDate birthDate;
    QString handicap;
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
};

#endif // USER_H
