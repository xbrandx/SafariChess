#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>
#include "animal.h"
#include "cell.h"
//#include "safari.h"
#include "game.h"
#include "ui_gameboard.h"

class Game;

namespace Ui {
class GameBoard;
}

class GameBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();
    void resizeEvent(QResizeEvent *); // resize the window

private slots:
    void on_actionNew_triggered();

private:
    Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
