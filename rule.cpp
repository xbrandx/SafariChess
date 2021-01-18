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
