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

    // Modification de la photo de l'utilisateur
    void SetPhoto();

    // Enregistre les modifications apportées à l'utilisateur dans la base de données
    void Validate();

    // Supprime l'utilisateur ainsi que tous ses composants
    void Delete();

};

#endif EDITUSER_H
