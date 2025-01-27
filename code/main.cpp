#include "game.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/img/img/splash.png"));
    splash.show();

    QTimer::singleShot(2000, [&]() { // define a duração da splshscreen
        game = new Game();
        game->show();
        splash.close();
    });
    return a.exec();
}
