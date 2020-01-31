#ifndef CSON_H
#define CSON_H
#include <QtTextToSpeech/QTextToSpeech>
#include <QMediaPlayer>

class CSon
{
public:
    CSon();
    void lecture();
    void stop();
    void parle(QString tex);
    QTextToSpeech * cara = new QTextToSpeech;

private:

    QMediaPlayer * Rat = new QMediaPlayer();
    //contien la racine du ficher audio.mp3/.wave
    QString m_fichierSon = ":/Storage/Tablet/Music/les-ratz-pas-de-panique-a-bord-clip-officiel.mp3" ;
    QString m_phraseDite = "et bien le bonjour je suis cara";
};

#endif // CSON_H
