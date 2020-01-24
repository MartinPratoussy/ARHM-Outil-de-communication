#ifndef USER_H
#define USER_H

#include <QDate>


class user
{
private:
    QString firstname;
    QString lastname;
    QDate birthDate;
    QString handicap;

public:
    user();
    user(QString firstname, QString lastname, QDate birthDate, QString handicap);
    ~user();

    void DisplayInterface();
    void EditFirstname(QString firstname);
    void EditLastname(QString lastname);
    void EditBirthDate(QDate birthDate);
    void EditHandicap(QString handicap);
    void Delete();
};

#endif // USER_H
