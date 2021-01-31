#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QList>
#include "animal.h"
#include "cell.h"

class Cell;
class Animal;

class Game
{
protected:
    QWidget *parent;
public:
    QList<Cell *> cells;
    int counter = 0;

    Game(QWidget *par);
    virtual ~Game();
    void AddCell(Cell* c);
 //   void Clear();
    virtual void Load()=0;
};

#endif // GAME_H
