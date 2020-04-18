#ifndef DISPARO_H
#define DISPARO_H

//#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

//class Disparo: public QObject,public QGraphicsEllipseItem{
class Disparo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Disparo(QGraphicsItem * p=0);
public slots:
    void move();
};

#endif // DISPARO_H
