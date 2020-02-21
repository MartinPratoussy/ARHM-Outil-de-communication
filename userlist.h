#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100

#include <QMainWindow>

#include <QScrollArea>

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

    // Affiche la liste des utilisateurs sous forme boutons vers leur interface
    void ShowUserList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserList *ui;

    // Tableau contenant tous les utilisateurs de l'application
    Interface * interface[NB_MAX_USER];

    // Boutons d'accès aux interfaces
    QPushButton * button[NB_MAX_USER];

    // Bouton d'ajout d'utilisateur
    QPushButton * addUserButton;

    // Nombre d'utilisateur dans la liste
    int nbUser = 0;

    // Taille de la fenêtre
    int width;
    int height;

    // Zone de scrolling
    QScrollArea * area;
};

#endif // USERLIST_H
