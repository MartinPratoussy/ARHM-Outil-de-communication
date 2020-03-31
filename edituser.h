#ifndef EDITUSER_H
#define EDITUSER_H

#include "addedituser.h"

class EditUser : public AddEditUser
{
public:
    EditUser();

    // Getter de l'utilisateur
    User* GetUser();

    // Supprime l'utilisateur
    void DeleteUser();

    // Initialise l'interface d'édition d'utilisateur
    void InitInterface(User* user, QSqlQuery* query);

    // Enregistrement de informations dans la base de données 
    void Validate(QString lastname, QString firstname, QString birthDate);

private slots:
    void on_validationButton_clicked();

private:

    // Utilisateur concerné par l'édition
    User* user;

};

#endif EDITUSER_H
