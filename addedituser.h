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

private slots:
    // Slot liant le bouton de validation avec la méthode virtuelle Validate()
    void on_validationButton_clicked();
    // Slot du bouton de photo
    void on_photoButton_clicked();
    // Slot liant le bouton d'annulation avec la méthode close()
    void on_cancelButton_clicked();

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
