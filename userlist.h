#ifndef USERLIST_H
#define USERLIST_H

#define NB_MAX_USER 100
#define NB_USER_DISPLAYABLE 8

#define WIDTH_PIECES 17
#define HEIGHT_PIECES 9

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

    // Utilisateurs
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

    // Mapper des boutons d'interface et d"édition
    QSignalMapper* interfaceMapper;
    QSignalMapper* editMapper;

    // Nombre d'utilisateur dans la liste
    QList<int> usersId;

    // Nombre d'utilisateur dans la liste
    int nbUser = 0;

    // Taille de la fenêtre
    int width;
    int height;

    // Zone de scrolling
    QScrollArea* area;

    // Connexion à la base de données
    void ConnectToDatabase();
    // Récupération des utlisateurs présents dans la base de données
    void LoadUsers();
    // Initialise la taille de la fenêtre
    void SetDisplayGeometry();
    // Affiche la liste des utilisateurs sous forme boutons vers leur interface
    void ShowUserList();
};

#endif // USERLIST_H
