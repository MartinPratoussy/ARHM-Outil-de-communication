#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100

#include <QMainWindow>

#include <QScrollArea>

#include "edituser.h"
#include "adduser.h"

namespace Ui {
class UserList;
}

class UserList : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

    // Affiche la liste des utilisateurs sous forme boutons vers leur interface
    void ShowUserList();

private slots:
    // Clic sur un bouton d'accès à une interface utilisateur
    void on_interfaceButton_clicked(int numUser);

    // Clic sur un bouton d'édition d'utilisateur
    void on_editButton_clicked(int numUser);

    // Clic sur le bouton d'ajout d'utilisateur
    void on_addButton_clicked();

private:
    Ui::UserList *ui;

    // Pointeurs de la base de données et de la requête SQL
    QSqlDatabase* database;
    QSqlQuery* query;

    User* user[NB_MAX_USER];

    // Interface utilisateur
    Interface* interface;

    // Interfaces d'édition utilisateur
    EditUser* userEdits;

    // Interface d'ajout d'utilisateur
    AddUser* addUser;

    // Boutons d'accès aux interfaces
    QPushButton* interfaceButton[NB_MAX_USER];

    // Boutons d'édition des utilisateurs
    QPushButton* editButton[NB_MAX_USER];

    // Bouton d'ajout d'utilisateur
    QPushButton* addUserButton;

    // Nombre d'utilisateur dans la liste
    int nbUser = 0;

    // Taille de la fenêtre
    int width;
    int height;

    // Zone de scrolling
    QScrollArea* area;
};

#endif // USERLIST_H
