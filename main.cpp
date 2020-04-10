#include "mainimport.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainImport w;
    w.show();
    return a.exec();
}
