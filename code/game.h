#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include <QGraphicsTextItem>

class Game: public QGraphicsView {

public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    QTimer *getSpawnTimer();
    QTimer *spawnTimer;
    void pause();
    void resume();
    void restart();
    void gameOver();

    static Game* game;
    QGraphicsTextItem *pausedText;
    QGraphicsTextItem *gameOverText;
    QGraphicsTextItem *instructionsText;
};

#endif // GAME_H
