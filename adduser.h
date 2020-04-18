#ifndef ADDUSER_H
#define ADDUSER_H

#include "addedituser.h"

class AddUser : public AddEditUser
{
public:
    // Initialise l'interface d'ajout d'utilisateur
    AddUser(QSqlDatabase * database, QSqlQuery* query);

    // Enregistrement de informations dans la base de données 
    void Validate();

    // Méthode de factorisation de l'enregistrement des catégories dans la base de données
    void InsertCategories(QString category);
};

#endif ADDUSER_H