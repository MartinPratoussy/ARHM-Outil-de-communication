#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100

#include <QMainWindow>

#include "user.h"

namespace Ui {
class UserList;
}

class UserList : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

private slots:
    // Ajoute un utlisateur à l'application
    void addUser(User user);
    // Edite l'utilisateur choisi
    void EditUser(User user);
    // Supprime un utlisateur de l'application
    void deleteUser(User user);

private:
    Ui::UserList *ui;

    // Nombre d'utilisateur enregistrés dans l'application
    int nbUser;
    // Tableau contenant tous les utilisateurs de l'application
    User user[NB_MAX_USER];

};

#endif // USERLIST_H
