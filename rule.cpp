#include "rule.h"

bool RuleGeneral::Enforce(Cell *c, Animal *a)
{
    return c->Empty();
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return a->Pieces()==MOUSE;
}

bool RuleBlueBase::Enforce(Cell *c, Animal *a)
{
    return a->Colors()==RED;
}

bool RuleRedBase::Enforce(Cell *c, Animal *a)
{
    return a->Colors()==BLUE;
}
