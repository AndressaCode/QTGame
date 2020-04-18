#include "Pontos.h"
#include <QFont>

Pontos::Pontos(QGraphicsItem * p): QGraphicsTextItem(p){
    pontos = 0; // inicia pontuacao em 0

    setPlainText(QString("Pontuacao: ") + QString::number(pontos)); // escreve o texto na tela e pega o numero de pontos
    setDefaultTextColor(Qt::green); // cor da fonte 14
    setFont(QFont("utopia", 14)); // fonte utopia tamanho 14

}

void Pontos::incrementa(){ // incrementa pontuacao do player
    pontos++;
    setPlainText(QString("Pontuacao: ") + QString::number(pontos));
}

int Pontos::getPontos(){ // pega n de pontos
    return pontos;
}
