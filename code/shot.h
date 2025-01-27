#ifndef SHOT_H
#define SHOT_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Shot: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Shot(QGraphicsItem * parent = 0);
    ~Shot();

public slots:
    void move();

private:
    QMovie *shotAnimation;
};

#endif // SHOT_H
