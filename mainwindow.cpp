#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    michel.lecture();
}

void MainWindow::on_pushButton_2_clicked()
{
    michel.stop();
}

void MainWindow::on_Parle_clicked()
{
    // mise en survéillence
    try
    {
    michel.parle(this->ui->textEnLecture->toPlainText());
    }
    catch (QString e)
    {
        this->ui->logError->setText(e);
    }
}


