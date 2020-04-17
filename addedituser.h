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
    virtual ~AddEditUser() = 0;

    // Méthode virtuelle de validation des données saisies
    virtual void Validate();

private slots:
    void on_validationButton_clicked();

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
