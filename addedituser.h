#ifndef ADDEDITUSER_H
#define ADDEDITUSER_H

#include <QWidget>

#include <QTextEdit>
#include <QDateEdit>
#include <QFileDialog>

#include "interface.h"

namespace Ui {
class AddEditUser;
}

class AddEditUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddEditUser(QWidget *parent = nullptr);
    ~AddEditUser();

    virtual void Validate();

    virtual void SetPhoto();

    virtual void Delete();

signals:
    // Envoi un signal quand un utilisateur a été créé
    void UpdateUsers();

private slots:
    // Slot du bouton de validation
    void on_validationButton_clicked();
    // Slot du bouton de photo
    void on_photoButton_clicked();
    // Slot du bouton de suppression
    void on_deleteButton_clicked();

protected:
    Ui::AddEditUser *ui;

    // Pointeur de la base de données
    QSqlDatabase* database;

    // Pointeur de la requête SQL
    QSqlQuery* query;

    // Variable permettant de contourner le problème des méthodes qui s'exécutent 2 fois
    bool isActive = true;
};

#endif // ADDEDITUSER_H
