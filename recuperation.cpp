#include "recuperation.h"
#include "ui_recuperation.h"

recuperation::recuperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recuperation)
{
    ui->setupUi(this);
}

recuperation::~recuperation()
{
    delete ui;
}
