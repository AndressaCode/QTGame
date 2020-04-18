#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Pontos.h"
#include "Life.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView{
public:
    Game(QWidget * p=0);

    QGraphicsScene * cenario;
    Player * player;
    Pontos * pontos;
    Life * life;

};

#endif // GAME_H
