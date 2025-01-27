#include "shot.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QMovie>

extern Game *game;

Shot::Shot(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), shotAnimation(new QMovie(":/img/img/fireball.gif")){
    if (shotAnimation->isValid()) {
        setPixmap(shotAnimation->currentPixmap());
        connect(shotAnimation, &QMovie::frameChanged, this, [=]() {
            setPixmap(shotAnimation->currentPixmap());
        });
        shotAnimation->start();
    }else{
        setPixmap(QPixmap(":/img/img/fireball.gif"));
    }

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Shot::move);
    moveTimer->start(50); // define o intervalo de movimento do tiro
}

Shot::~Shot(){
    delete shotAnimation;
}

void Shot::move(){
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (QGraphicsItem *item : collidingItemsList) {
        if (typeid(*item) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(item);
            scene()->removeItem(this);
            delete item;
            delete this;
            return;
        }
    }
    setPos(x(), y() - 10);
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
