#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100

#include <QMainWindow>

#include <QScrollArea>

#include "interface.h"

#include "adduser.h"
#include "edituser.h

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
    void on_interfaceButton_clicked(int numUser);

    void on_editButton_clicked(int numUser);

    void on_addButton_clicked();

private:
    Ui::UserList *ui;

    // Pointeur de la base de données
    QSqlDatabase* database;
    QSqlQuery* query;

    // Tableau contenant tous les interfaces utilisateurs de l'application
    Interface* interface[NB_MAX_USER];

    // Tableau contenant tous les interfaces d'édition de l'application
    EditUser* userEdits[NB_MAX_USER];

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
