#ifndef PLAYER_H
#define PLAYER_H

//#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

//class Player:public QObject, public QGraphicsEllipseItem{
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * p=0);
    void keyPressEvent(QKeyEvent * e);
public slots:
    void prod();
private:
    QMediaPlayer * soundDisp;
};

#endif // PLAYER_H
