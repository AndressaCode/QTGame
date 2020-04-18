#include "Life.h"
#include <QFont>

Life::Life(QGraphicsItem * p): QGraphicsTextItem(p){
    life = 3; // inicia com 3 vidas

    setPlainText(QString("Lifes: ") + QString::number(life));
    setDefaultTextColor(Qt::blue); // cor do texto azul
    setFont(QFont("utopia",14)); // fonte utopia tamanho 14

}

void Life::decrementa(){ // decrementa o numero de vidas do player
    life--;
    setPlainText(QString("Life: ") + QString::number(life));
}

int Life::getLife(){ // pega n de vidas
    return life;
}
