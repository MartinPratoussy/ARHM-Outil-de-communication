#include "addedituser.h"
#include "ui_addedituser.h"

AddEditUser::AddEditUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditUser)
{
    ui->setupUi(this);
}

AddEditUser::~AddEditUser()
{
    delete ui;
}

void AddEditUser::on_validationButton_clicked()
{
    Validate(this->firstnameEdit->toPlainText(), this->lastnameEdit->toPlainText(), this->birtDateEdit->date, this->handicapEdit->toPlainText());
}
