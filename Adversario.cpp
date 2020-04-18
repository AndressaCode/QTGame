#include "Adversario.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>
#include <QList>
#include <stdlib.h> // implementa a funcao rand
#include "Life.h"

extern Game * game;

//Adversario::Adversario(QGraphicsItem * p): QObject(), QGraphicsEllipseItem(p){
Adversario::Adversario(QGraphicsItem * p): QObject(), QGraphicsPixmapItem(p){

    int num_ale = rand() % 700; // numero aleatorio de adversarios cai dentro de 700 px, n menor que o definido para tela
    setPos(num_ale, 0);
    //setRect(0, 0, 60, 60); // tamanho do adversario

    //setPixmap(QPixmap(":/images/steel_ball.png"));
    setPixmap(QPixmap(":/images/ball.png"));
    setTransformOriginPoint(50,50);

    //connect a um temporizador
    QTimer * temp = new QTimer(this);
    connect(temp, SIGNAL(timeout()), this, SLOT(move()));

    temp->start(50);
}

void Adversario::move(){
    // chamar funcao decrementar vidas

    setPos(x(), y()+2); // velocidade que o adversario cai
    if (pos().y() > 640){
        game->life->decrementa();
        scene()->removeItem(this);
        delete this;
    }
}
