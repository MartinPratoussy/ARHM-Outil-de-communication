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

void AddEditUser::InitUserEditsInterface(User * user, QSqlQuery * query)
{
    this->user = user;
    this->query = query;

    lastnameEdit = new QTextEdit(this->user->getLastname(), this);
    firstnameEdit = new QTextEdit(this->user->getFirstname(), this);
    birtDateEdit = new QDateEdit(this->user->getBirthDate(), this);
    handicapEdit = new QTextEdit(this->user->getHandicap(), this);
    validation = new QPushButton("Valider", this);

    connect(validation, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

User * AddEditUser::GetUser()
{
    return this->user;
}

void AddEditUser::on_validationButton_clicked()
{
    EditFirstname(this->firstnameEdit->toPlainText());
    EditLastname(this->lastnameEdit->toPlainText());
    EditBirthDate(this->birtDateEdit->date());
    EditHandicap(this->handicapEdit->toPlainText());
}

void AddEditUser::EditFirstname(QString firstname)
{
    this->user->setFirstname(firstname, this->query);
}

void AddEditUser::EditLastname(QString lastname)
{
    this->user->setLastname(lastname, this->query);
}

void AddEditUser::EditBirthDate(QDate birthDate)
{
    this->user->setBirthDate(birthDate, this->query);
}

void AddEditUser::EditHandicap(QString handicap)
{
    this->user->setHandicap(handicap, this->query);
}
