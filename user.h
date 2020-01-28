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
    ~User();

    // Nombre d'utilisateurs enregistrés dans l'application
    static int nbUser;

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
