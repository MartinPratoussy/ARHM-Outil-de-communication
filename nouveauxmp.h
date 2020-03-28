#ifndef NOUVEAUXMP_H
#define NOUVEAUXMP_H

#include <QDialog>

namespace Ui {
class nouveauxMp;
}

class nouveauxMp : public QDialog
{
    Q_OBJECT

public:
    explicit nouveauxMp(QWidget *parent = nullptr);
    ~nouveauxMp();

private:
    Ui::nouveauxMp *ui;
};

#endif // NOUVEAUXMP_H
