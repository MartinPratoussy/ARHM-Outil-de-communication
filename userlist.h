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

signals:
    // Ajoute un utlisateur à l'application
    void AddUser(User user);
    // Edite l'utilisateur choisi
    void EditUser(User user);

private:
    Ui::UserList *ui;

    // Nombre d'utilisateur enregistrés dans l'application
    int nbUser;
    // Tableau contenant tous les utilisateurs de l'application
    User user[NB_MAX_USER];

};

#endif // USERLIST_H
