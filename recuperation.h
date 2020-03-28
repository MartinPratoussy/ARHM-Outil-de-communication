#ifndef RECUPERATION_H
#define RECUPERATION_H

#include <QWidget>

namespace Ui {
class recuperation;
}

class recuperation : public QWidget
{
    Q_OBJECT

public:
    explicit recuperation(QWidget *parent = nullptr);
    ~recuperation();

private:
    Ui::recuperation *ui;
};

#endif // RECUPERATION_H
