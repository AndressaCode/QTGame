#include "Disparo.h"
#include "Adversario.h"
#include "Pontos.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <typeinfo>

extern Game * game;

//Disparo::Disparo(QGraphicsItem * p): QObject(),QGraphicsEllipseItem(p){
Disparo::Disparo(QGraphicsItem * p): QObject(),QGraphicsPixmapItem(p){
    // desenha o tiro
    // setRect(0,0,15,15);
    setPixmap(QPixmap(":/images/fire.png"));

    // conectar ao temporizador
    QTimer * temp = new QTimer();
    connect(temp,SIGNAL(timeout()),this,SLOT(move()));

    temp->start(45);
}

void Disparo::move(){ //verifica se ha colisao entre os objetos disparo e adversario
    // dispara para cima
    QList<QGraphicsItem *> choc_obj = collidingItems();
    for(int i=0, nc=choc_obj.size(); i<nc; ++i){
        if(typeid(*(choc_obj[i])) == typeid(Adversario)){ // caso sim, os dois sao deletados do cenario
            // chamar aqui funcao para incrementar pontos

            game->pontos->incrementa();
            scene()->removeItem(choc_obj[i]);
            scene()->removeItem(this);

            delete choc_obj[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if (pos().y() < 0){ // deleta o disparo caso saia da tela
            scene()->removeItem(this);
            delete this;
    }
}
