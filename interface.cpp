#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::Cancel()
{
    *sentence[numLevel] = "";
    numLevel--;
}

Interface & Interface::operator=(const Interface & interface)
{
    *this->pictos = *interface.pictos;
    *this->sentence = *interface.sentence;
    this->numLevel = interface.numLevel;

    return * this;
}
