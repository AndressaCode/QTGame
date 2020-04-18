#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Disparo.h"
#include "Adversario.h"
//#include <QMediaPlayer>

//Player::Player(QGraphicsItem * p): QGraphicsEllipseItem(p){
Player::Player(QGraphicsItem *p): QGraphicsPixmapItem(p){
    soundDisp = new QMediaPlayer();
    soundDisp->setMedia(QUrl("qrc:/sounds/Explosion8.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *e){
    if (e->key() == Qt::Key_Left){ // antes de mover o objeto na tela para esquerda,
        if (pos().x() > 0){          // verifica se a posicao que esta eh maior que 0,
            setPos(x()-25, y());   // caso sim ele permite se mover na tela
        }
    }
    else if (e->key() == Qt::Key_Right){ // caso seja pressiionado no teclado para direita,
            if (pos().x() + 100 <= 860){ // verifica se o x do objeto eh menor ou igual ao tamanho da tela definido como 800
                setPos(x()+25,y());      // caso sim ele se move ate essa posicao
            }
    }
    else if (e->key() == Qt::Key_Up){
         if (pos().y() > 0){
            setPos(x(),y()-25);
        }
     }
    else if (e->key() == Qt::Key_Down){
         if (pos().y() + 100 <= 660){
            setPos(x(),y()+25);
        }
   }
    else if (e->key() == Qt::Key_Space){ // dispara quando a barra de espaço eh pressionada
            Disparo * disparo = new Disparo(); // cria um novo objeto disparo
            disparo->setPos(x(),y());  // faz o disparo para cima caso o spacebar seja apertado
            scene()->addItem(disparo); // adiciona o disparo ao cenario
    }
    // reproduz som do disparo
     if (soundDisp->state() == QMediaPlayer::PlayingState){
         soundDisp->setPosition(0);
        }
        else if (soundDisp->state() == QMediaPlayer::StoppedState){
                 soundDisp->play();
         }
}
void Player::prod(){
    Adversario * adversario = new Adversario();
    scene()->addItem(adversario);
}
