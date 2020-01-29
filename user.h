#ifndef USER_H
#define USER_H

#define NB_MAX_USER 100

#include <QDate>

#include "interface.h"

// Classe représentant un utlisateur de l'application
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT
private:
    Ui::User * ui;

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

    // Nombre d'utilisateurs enregistrés dans l'application
    static int nbUser;

    // Getters des attributs privés
    QString getFirstname();
    QString getLastname();
    QDate getBirthDate();
    QString getHandicap();
    Interface getInterface();

    // Surcharge de l'opérateur d'affection
    User & operator=(const User & user);

};

#endif // USER_H
