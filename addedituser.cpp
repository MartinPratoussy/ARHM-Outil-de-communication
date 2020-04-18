#include "addedituser.h"
#include "ui_addedituser.h"

AddEditUser::AddEditUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditUser)
{
    ui->setupUi(this);
    connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

AddEditUser::~AddEditUser()
{
    delete ui;
}

void AddEditUser::Validate()
{
}

void AddEditUser::on_validationButton_clicked()
{
    Validate();
}

void AddEditUser::on_cancelButton_clicked()
{
    this->close();
}
