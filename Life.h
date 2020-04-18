#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsTextItem>

class Life: public QGraphicsTextItem{
public:
    Life(QGraphicsItem * p=0);
    void decrementa();
    int getLife();
private:
    int life;
};

#endif // LIFE_H
