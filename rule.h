#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include <QDebug>
#include "cell.h"
#include "animal.h"

class Animal;
class Cell;

class Rule  //abstract base class
{
public:
    virtual bool Enforce(Cell *c, Animal *a)=0;
};

class RuleGeneral : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

class RuleRiver : public Rule
{
    bool Enforce(Cell *c, Animal *a);
};

#endif // RULE_H
