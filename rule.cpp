#include "rule.h"

bool RuleGeneral::Enforce(Cell *c, Animal *a)
{
    qDebug() << "general rule";
    return true;
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    qDebug() << "river rule";
    return a->Pieces()==MOUSE;
}

bool RuleBlueBase::Enforce(Cell *c, Animal *a)
{
    qDebug() << "blue base rule";
    return a->Colors()==RED;
}

bool RuleRedBase::Enforce(Cell *c, Animal *a)
{
    qDebug() << "red base rule";
    return a->Colors()==BLUE;
}
