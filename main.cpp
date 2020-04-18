#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication qtgameAndressa(argc, argv);

    game = new Game();
    game->show();

    return qtgameAndressa.exec();
}
