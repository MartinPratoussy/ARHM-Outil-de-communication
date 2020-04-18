#ifndef ADDUSER_H
#define ADDUSER_H

#include "addedituser.h"

class AddUser : public AddEditUser
{
public:
    // Initialise l'interface d'ajout d'utilisateur
    AddUser(QSqlDatabase * database, QSqlQuery* query);

    // Enregistrement de informations dans la base de donn�es 
    void Validate();

    // M�thode de factorisation de l'enregistrement des cat�gories dans la base de donn�es
    void InsertCategories(QString category);
};

#endif ADDUSER_H