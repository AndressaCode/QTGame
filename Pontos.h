#ifndef PONTOS_H
#define PONTOS_H

#include <QGraphicsTextItem>

class Pontos: public QGraphicsTextItem{
public:
    Pontos(QGraphicsItem * p=0);
    void incrementa();
    int getPontos();
private:
    int pontos;
};

#endif // PONTOS_H
