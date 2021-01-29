#include "rule.h"

bool RuleGrass::Enforce(Cell *c, Animal *a)
{
    return c->Empty() || (a->Pieces() >= c->Zoo()->Pieces() && a->Colors() != c->Zoo()->Colors());
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    return (c->Empty() || a->Pieces() == c->Zoo()->Pieces()) && a->Pieces()==MOUSE;
}

bool RuleRedTrap::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    if (c->Empty())
    {
        ok = true;
    } else if (a->Colors()==RED && c->Zoo()->Colors()==RED)
    {
        ok = false;
    } else if (a->Colors()==RED && c->Zoo()->Colors()==BLUE)
    {
        ok = true;
    } else if (a->Colors()==BLUE && c->Zoo()->Colors()==RED)
    {
        if (a->Pieces() >= c->Zoo()->Pieces())
        {
            ok = true;
        }  else
        {
            ok = false;
        }
    } else
    {
        ok = false;
    }
    return ok;
}

bool RuleBlueTrap::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    if (c->Empty())
    {
        ok = true;
    } else if (a->Colors()==BLUE && c->Zoo()->Colors()==BLUE)
    {
        ok = false;
    } else if (a->Colors()==BLUE && c->Zoo()->Colors()==RED)
    {
        ok = true;
    } else if (a->Colors()==RED && c->Zoo()->Colors()==BLUE)
    {
        if (a->Pieces() >= c->Zoo()->Pieces())
        {
            ok = true;
        }  else
        {
            ok = false;
        }
    } else
    {
        ok = false;
    }
    return ok;
}

bool RuleRedBase::Enforce(Cell *c, Animal *a)
{
    return c->Empty() && a->Colors()==BLUE;
}

bool RuleBlueBase::Enforce(Cell *c, Animal *a)
{
    return c->Empty() && a->Colors()==RED;
}
