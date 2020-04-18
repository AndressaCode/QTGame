#ifndef ADVERSARIO_H
#define ADVERSARIO_H

//#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

//class Adversario: public QObject,public QGraphicsEllipseItem{
class Adversario: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Adversario(QGraphicsItem * p=0);
public slots:
    void move();
};

#endif // ADVERSARIO_H
