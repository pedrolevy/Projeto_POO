#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMovie>
#include <cstdlib>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), moveTimer(new QTimer(this)) {

    // gera uma posição aleatória para o inimigo no eixo X
    int randomX = rand() % 500;
    setPos(randomX, 0);

    // carrega o gif do zumbi
    QMovie *movie = new QMovie(":/img/img/zombie.gif");
    setPixmap(movie->currentPixmap());
    connect(movie, &QMovie::updated, this, [this, movie]() {
        setPixmap(movie->currentPixmap());
    });
    movie->start();
    movie->setScaledSize(QSize(57, 100));

    // define o tempo de deslocamento do zumbi
    connect(moveTimer, &QTimer::timeout, this, &Enemy::move);
    if (rand() % 3 == 0) {
        moveTimer->start(50);
     }else{
        moveTimer->start(20);
     }
}

void Enemy::move() {
    setPos(x(), y() + 5); // movimentação do zumbi para baixo
    if (pos().y() > 600) { // exclui o zumbi assim que ele sai da tela
        scene()->removeItem(this);
        delete this;
        game->gameOver();
        return;
    }
}

void Enemy::pause() {
    moveTimer->stop();
}

void Enemy::resume() {
    moveTimer->start(50);
}
