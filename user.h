#ifndef USER_H
#define USER_H

#include <QDate>

// Classe représentant un utlisateur de l'application
class user
{
private:
    QString firstname;
    QString lastname;
    QDate birthDate;
    QString handicap;

public:
    user();
    user(QString firstname, QString lastname, QDate birthDate, QString handicap);
    ~user();

    // Affiche l'interface personnalisée de l'utlisateur
    void DisplayInterface();
    // Edite les différents attributs de l'utlisateur
    void EditFirstname(QString firstname);
    void EditLastname(QString lastname);
    void EditBirthDate(QDate birthDate);
    void EditHandicap(QString handicap);
    // Supprime l'utlisateur
    void Delete();
};

#endif // USER_H
