#ifndef PICTOGRAM_H
#define PICTOGRAM_H

#include <QtTextToSpeech/QTextToSpeech>
#include <QPixmap>

class Pictogram
{
private:
    QString definition;
    QPixmap image;
    QTextToSpeech * speech = new QTextToSpeech();
public:
    Pictogram();
    Pictogram(QString definition, QPixmap image);
    ~Pictogram();
};

#endif // PICTOGRAM_H
