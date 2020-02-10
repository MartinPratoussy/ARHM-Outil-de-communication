#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

#include "user.h"

namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    void InitInterface(User * user);
    ~Interface();

    // Annule l'action précédente
    void Cancel();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

private slots:
    void on_jeVeuxButton_clicked();

    void on_jeSuisButton_clicked();

    void on_objetsButton_clicked();

    void on_personnesButton_clicked();

private:
    Ui::Interface *ui;

    // Phrase créée par l'utilisateur
    QString * sentence[3];
    // Nombre d'étapes de la phrase effectuées
    int numLevel = 0;
    // Utilisateur de l'interface
    User * user;
};

#endif // INTERFACE_H
