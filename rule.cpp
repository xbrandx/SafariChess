#include "rule.h"

bool RuleGeneral::Enforce(Cell *c, Animal *a)
{
    return c->Empty();
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return c->Empty() && a->Pieces()==MOUSE;
}

bool RuleBlueBase::Enforce(Cell *c, Animal *a)
{
    return c->Empty() && a->Colors()==RED;
}

bool RuleRedBase::Enforce(Cell *c, Animal *a)
{
    return c->Empty() && a->Colors()==BLUE;
}
