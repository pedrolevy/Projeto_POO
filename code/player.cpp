#include "player.h"
#include "game.h"
#include "shot.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QMovie>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), paused(false) {

    QMovie *movie = new QMovie(":/img/img/you.gif");
    setPixmap(movie->currentPixmap());
    connect(movie, &QMovie::updated, this, [this, movie]() {
        setPixmap(movie->currentPixmap());
    });
    movie->start();
    movie->setScaledSize(QSize(46, 100));
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_P) {
        paused = !paused;
        for (auto enemy : scene()->items()) {
            Enemy* enemyItem = dynamic_cast<Enemy*>(enemy);
            if (enemyItem) {
                if (paused) {
                    enemyItem->pause();
                } else {
                    enemyItem->resume();
                }
            }
        }

        if (paused) {
            Game::game->pause();
        } else {
            Game::game->resume();
        }
    }
    if (paused) {
        return;
    }

    switch (event->key()) {
    case Qt::Key_R:
        Game::game->restart();
        return;
        break;
    }

    switch (event->key()) {
    case Qt::Key_Left:
        if (pos().x() > 0) {
            setPos(x() - 30, y());
        }
        break;

    case Qt::Key_Right:
        if (pos().x() + 100 < 800) {
            setPos(x() + 30, y());
        }
        break;

    case Qt::Key_Up:
        if (pos().y() > 400) {
            setPos(x(), y() - 30);
        }
        break;

    case Qt::Key_Down:
        if (pos().y() + 100 < 600) {
            setPos(x(), y() + 30);
        }
        break;

    case Qt::Key_Space:
    {
        Shot *shot = new Shot();
        shot->setPos(x() - 5, y() - 40);  // posição inicial do tiro
        scene()->addItem(shot);
    }
    break;

    default:
        QGraphicsPixmapItem::keyPressEvent(event);
        break;
    }
}

void Player::spawn() {
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
