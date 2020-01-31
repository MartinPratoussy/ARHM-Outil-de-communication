#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QObject>
#include "cson.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CSon michel;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_Parle_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
