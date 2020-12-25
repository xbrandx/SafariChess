#ifndef RULE_H
#define RULE_H

#include <QWidget>

class Animal;
class Cell;
class Rule  //abstract base class
{
public:
    virtual bool Enforce(Cell *c, Animal *a)=0;
};

class RuleRiver:public Rule{
    bool Enforce(Cell *c, Animal *a);
};

#endif // RULE_H
