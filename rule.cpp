#include "rule.h"

bool RuleGeneral::Enforce(Cell *c, Animal *a)
{
    return true;
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return a->Pieces()==MOUSE;
}
