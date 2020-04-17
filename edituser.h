#ifndef EDITUSER_H
#define EDITUSER_H

#include "addedituser.h"

class EditUser : public AddEditUser
{
public:
    EditUser(User* user);

    // Getter de l'utilisateur
    User* GetUser();

    // Initialise l'interface d'�dition d'utilisateur
    void InitInterface(QSqlQuery* query);

    // Enregistre les modifications apport�es � l'utilisateur dans la base de donn�es
    void Validate();

private slots:

    void on_deleteButton_clicked();

private:

    // Utilisateur concern� par l'�dition
    User* user;

};

#endif EDITUSER_H
