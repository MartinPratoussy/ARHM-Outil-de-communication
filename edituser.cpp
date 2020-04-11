#include "edituser.h"
#include "ui_addedituser.h"

EditUser::EditUser(User* user)
{
    this->user = user;

    connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
    connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(on_cancelButton_clicked()));
}

void EditUser::InitInterface(QSqlQuery* query)
{
    AddEditUser::query = query;

    ui->lastnameEdit->setText(this->user->getLastname());
    ui->firstnameEdit->setText(this->user->getFirstname());
    ui->birthDateEdit->setDate(QDate::fromString(this->user->getBirthDate(), "dd/MM/yyyy"));
}

User* EditUser::GetUser()
{
    return this->user;
}

void EditUser::on_validationButton_clicked()
{
    this->user->setFirstname(ui->firstnameEdit->toPlainText(), query);
    this->user->setLastname(ui->lastnameEdit->toPlainText(), query);
    this->user->setBirthDate(ui->birthDateEdit->date().toString("dd/mm/YYYY"), query);
    this->parent->update();
    this->close();
}

void EditUser::on_deleteButton_clicked()
{
    if (!this->query->exec("DELETE FROM User WHERE userId = " + QString::number(this->user->getId()) + ";")) qWarning() << "ERROR: " << database->lastError().text();
    this->parent->update();
    this->close();
}

