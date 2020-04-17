#ifndef EDITUSER_H
#define EDITUSER_H

#include "addedituser.h"

class EditUser : public AddEditUser
{
public:
    EditUser(User* user);

    // Getter de l'utilisateur
    User* GetUser();

    // Initialise l'interface d'édition d'utilisateur
    void InitInterface(QSqlQuery* query);

    // Enregistre les modifications apportées à l'utilisateur dans la base de données
    void Validate();

private slots:

    void on_deleteButton_clicked();

private:

    // Utilisateur concerné par l'édition
    User* user;

};

#endif EDITUSER_H
