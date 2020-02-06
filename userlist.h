#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100

#include <QMainWindow>

#include "interface.h"

namespace Ui {
class UserList;
}

class UserList : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

private:
    Ui::UserList *ui;

    // Tableau contenant tous les utilisateurs de l'application
    User *user[NB_MAX_USER];

    int nbUser = 0;
};

#endif // USERLIST_H