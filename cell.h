#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
#include "rule.h"
#include "game.h"
#include "animal.h"
#include "gameboard.h"

class Animal;
class Rule;

const int DROPLAST = 6;
enum cellType{GRASS, RIVER, TRAP, RED_BASE, BLUE_BASE};

class Cell : public QLabel
{
private:
    Animal *zoo;
    int X, Y;
public:
    explicit Cell(int x, int y, QWidget *parent);
//    void paintEvent(QPaintEvent *);
//    int getX() const {return X;}
//    int getY() const {return Y;}
    void AcceptAnimal(Animal *a);
    void ReleaseAnimal(Animal *a);
    bool Empty(){return !zoo;}
    bool CanBeDropped(Animal *a);
    void FindClosestDrop(Animal* a);
    void AddDropRules(int n...);

    virtual Rule * DropRule(int i)=0;
    virtual void DropRule(int i, Rule *r)=0;
    virtual cellType Type()=0;
};


//Methods for inheriting classes----------------------------------------
class CellGrass : public Cell
{
private:
    static Rule *dropRules[DROPLAST];
public:
    CellGrass(int x, int y, QWidget *parent);
    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}
    cellType Type();
};

class CellRiver : public Cell
{
private:
    static Rule *dropRules[DROPLAST];
public:
    CellRiver(int x, int y, QWidget *parent);
    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}
    cellType Type();
};

class CellTrap : public Cell
{
private:
    static Rule *dropRules[DROPLAST];
public:
    CellTrap(int x, int y, QWidget *parent);
    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}
    cellType Type();
};

class CellRedBase : public Cell
{
private:
    static Rule *dropRules[DROPLAST];
public:
    CellRedBase(int x, int y, QWidget *parent);
    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}
    cellType Type();
};

class CellBlueBase : public Cell
{
private:
    static Rule *dropRules[DROPLAST];
public:
    CellBlueBase(int x, int y, QWidget *parent);
    Rule *DropRule(int i){return dropRules[i];}
    void DropRule(int i, Rule *r){dropRules[i] = r;}
    cellType Type();
};

#endif // CELL_H
