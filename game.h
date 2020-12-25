#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QList>

class Cell;
class Animal;

class Game
{
protected:
    QWidget *parent;
public:
    QList<Cell *> cells;
public:
    Game(QWidget *par);
    virtual ~Game();
    void AddCell(Cell* c);
 //   void Clear();
    virtual void Load()=0;
};

#endif // GAME_H
