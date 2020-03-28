#include "nouveauxmp.h"
#include "ui_nouveauxmp.h"

nouveauxMp::nouveauxMp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nouveauxMp)
{
    ui->setupUi(this);
}

nouveauxMp::~nouveauxMp()
{
    delete ui;
}
