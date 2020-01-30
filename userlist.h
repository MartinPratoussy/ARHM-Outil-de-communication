#ifndef USERLIST_H
#define USERLIST_H

#include <QMainWindow>

#include "useredits.h"

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

private slots:
    void on_edits_clicked();

private:
    Ui::UserList *ui;

    // Tableau contenant tous les utilisateurs de l'application
    User *user[NB_MAX_USER];

};

#endif // USERLIST_H
