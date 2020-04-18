#ifndef ADDEDITUSER_H
#define ADDEDITUSER_H

#include <QWidget>

#include <QTextEdit>
#include <QDateEdit>
#include <QSignalMapper>

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

private slots:
    // Slot liant le bouton de validation avec la méthode virtuelle Validate()
    void on_validationButton_clicked();
    // Slot liant le bouton d'annulation avec la méthode close()
    void on_cancelButton_clicked();

protected:
    Ui::AddEditUser *ui;

    // Pointeur de la base de données
    QSqlDatabase* database;

    // Pointeur de la requête SQL
    QSqlQuery* query;

    // Classe parent
    QSignalMapper* mapper;
};

#endif // ADDEDITUSER_H
