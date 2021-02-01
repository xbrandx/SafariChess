#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include <QDebug>
#include <QPoint>
#include <cmath>
#include "cell.h"
#include "animal.h"
#include "game.h"

class Animal;
class Cell;

class Rule  //abstract base class
{
public:
    virtual bool Enforce(Cell *c, Animal *a)=0;
};

class RuleGrass : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleRiver : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleRedTrap : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleBlueTrap : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleRedBase : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleBlueBase : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

#endif // RULE_H
