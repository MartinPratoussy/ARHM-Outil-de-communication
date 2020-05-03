#include "addedituser.h"
#include "ui_addedituser.h"

AddEditUser::AddEditUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditUser)
{
    ui->setupUi(this);

    // Connecte les boutons à leurs fonctions respectives
    connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
    connect(ui->photoButton, SIGNAL(released()), this, SLOT(on_photoButton_clicked()));
    connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
}

AddEditUser::~AddEditUser()
{
    delete ui;
}

void AddEditUser::Validate()
{
}

void AddEditUser::SetPhoto()
{
}

void AddEditUser::on_validationButton_clicked()
{
    Validate();
}

void AddEditUser::on_photoButton_clicked()
{
    SetPhoto();
}

void AddEditUser::on_cancelButton_clicked()
{
    this->close();
}
