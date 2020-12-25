#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include "rule.h"
#include "game.h"
#include "animal.h"
#include "gameboard.h"

class Animal;
class Rule;

const int DROPLAST = 6;
enum cellType{GRASS, RIVER, TRAP, BASE};

class Cell : public QLabel
{
private:
    Animal *zoo;
    int X, Y;
    static Rule *dropRules[DROPLAST];
public:
    explicit Cell(int x, int y, QWidget *parent);
    void AcceptAnimal(Animal *a);
//    void paintEvent(QPaintEvent *);

    void AddDropRules(int n...);

    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}

    void FindClosestDrop(Animal* a, QPoint c);
    bool CanBeDropped(Animal *a);

//    int getX() const {return X;}
//    int getY() const {return Y;}


};

class CellGrass : public Cell
{
public:
    CellGrass(int x, int y, QWidget *parent);
};

class CellRiver : public Cell
{
public:
    CellRiver(int x, int y, QWidget *parent);
};

class CellTrap : public Cell
{
public:
    CellTrap(int x, int y, QWidget *parent);
};

class CellBase : public Cell
{
public:
    CellBase(int x, int y, QWidget *parent);
};

#endif // CELL_H
