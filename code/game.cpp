#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

Game* Game::game = nullptr;

Game::Game(QWidget *parent) : QGraphicsView(parent){

    // cria a cena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/img/img/background.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // cria o jogador
    player = new Player();
    player->setPos(360, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // cria o score
    score = new Score();
    scene->addItem(score);

    // cria os inimigos
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, player, &Player::spawn);
    spawnTimer->start(2000); // Spawn a cada 2 segundos

    // cria o texto "PAUSED"
    pausedText = new QGraphicsTextItem("PAUSED");
    pausedText->setDefaultTextColor(Qt::white);
    pausedText->setFont(QFont("dotgothic16", 16, QFont::Bold));
    pausedText->setPos(5, 10);  // Posiciona o texto no centro da tela

    // cria o texto "GAME OVER"
    gameOverText = new QGraphicsTextItem("GAME OVER");
    gameOverText->setDefaultTextColor(Qt::white);
    gameOverText->setFont(QFont("dotgothic16", 26, QFont::Bold));
    gameOverText->setPos(300, 250);
    gameOverText->setVisible(false);  // Esconde inicialmente
    scene->addItem(gameOverText); //revisar

    // cria o texto de instruções
    instructionsText = new QGraphicsTextItem("←↑↓→ MOVE\nSpacebar SHOT\nP PAUSE\nR RESTART");
    instructionsText->setDefaultTextColor(Qt::white);
    instructionsText->setFont(QFont("dotgothic16", 10, QFont::Bold));
    instructionsText->setPos(700, 50);  // Posição das instruções
    scene->addItem(instructionsText);

    // exibe a janela
    game = this;
    show();
}

void Game::pause() {
    spawnTimer->stop();
    scene->addItem(pausedText);
}

void Game::restart() {
    spawnTimer->stop();
    spawnTimer->disconnect();
    QList<QGraphicsItem *> itemsToRemove = scene->items();
    for (QGraphicsItem *item : itemsToRemove) {
        if (item != gameOverText && item != pausedText) {
            scene->removeItem(item);
            delete item;
        }
    }

    // reinicia o player
    player = new Player();
    player->setPos(360, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // reinicia o score
    score = new Score();
    scene->addItem(score);

    // reinicia o timer de spawn
    connect(spawnTimer, &QTimer::timeout, player, &Player::spawn);
    spawnTimer->start(2000);
    gameOverText->setVisible(false);

    // mostra instruções na tela
    instructionsText = new QGraphicsTextItem("←↑↓→ MOVE\nSpacebar SHOT\nP PAUSE\nR RESTART");
    instructionsText->setDefaultTextColor(Qt::white);
    instructionsText->setFont(QFont("dotgothic16", 10, QFont::Bold));
    instructionsText->setPos(700, 50);  // Posição das instruções
    scene->addItem(instructionsText);
}

void Game::resume() {
    spawnTimer->start(2000);
    scene->removeItem(pausedText);
}

void Game::gameOver() {
    spawnTimer->stop();
    if (!gameOverText->isVisible()) {
        scene->addItem(gameOverText);
        gameOverText->setVisible(true);
    }
}
