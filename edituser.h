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

    // Initialise l'interface d'�dition d'utilisateur
    void InitUserEditsInterface(User* user, QSqlQuery* query);

    // Enregistrement de informations dans la base de donn�es 
    void Validate(QString lastname, QString firstname, QDate birthDate, QString handicap);

private:

    // Utilisateur concern� par l'�dition
    User* user;

};

#endif // EDITUSER_H
