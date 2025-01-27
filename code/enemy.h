#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Enemy(QGraphicsItem * parent = 0);
    void pause();
    void resume();

public slots:
    void move();

private:
    QTimer *moveTimer;
};

#endif // ENEMY_H
