#include "Game.h"
#include "Adversario.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>


Game::Game(QWidget *p){
    // cria o cenario
    cenario = new QGraphicsScene();
    cenario->setSceneRect(0,0,860,660);
    setBackgroundBrush(QBrush(QImage(":/images/landscape.png")));

    setScene(cenario);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(860,660); // tamanho da tela fixo

    // cria o jogador principal
    player = new Player();
    //player->setRect(0,0,75,75);
    player->setPos(430,580); // player posicionado ao meio da tela

    // torna o circulo objeto "foco" para se movimentar no cenario
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // adiciona o player ao cenario
    cenario->addItem(player);

    // cria o campo life e adiciona a tela
    life = new Life();
    cenario->addItem(life);

    // cria a pontuacao
    pontos = new Pontos();
    pontos->setPos(pontos->x(),pontos->y()+25);
    cenario->addItem(pontos);

    // gerando adversarios
    QTimer * temp = new QTimer();
    QObject::connect(temp,SIGNAL(timeout()),player,SLOT(prod()));
    temp->start(2000); // intervalo de criacao

    QMediaPlayer * mus = new QMediaPlayer();
    mus->setMedia(QUrl(":/sounds/Frantic-Gameplay.mp3"));
    mus->play();
    show();
}

