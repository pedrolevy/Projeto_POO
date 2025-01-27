#include "score.h"
#include <QFont>
#include <QGraphicsScene>
#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent), score(0) {
    setPlainText(QString("SCORE: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("dotgothic16", 16, QFont::Bold));
    setPos(800 - boundingRect().width() - 10, 10);
}

void Score::increase() {
    score++;
    setPlainText(QString("SCORE: ") + QString::number(score));
    setPos(800 - boundingRect().width() - 10, 10);
}

int Score::getScore() {
    return score;
}
