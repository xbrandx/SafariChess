#include "rule.h"

bool RuleGrass::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    if (c->Empty())
    {
        ok = true;
    } else if (a->Cells()->Type()==RIVER)
    {
        ok = false;
    } else if (a->Pieces()==MOUSE
               && c->Zoo()->Pieces()==ELEPHAN
               && a->Colors() != c->Zoo()->Colors())
    {
        ok = true;
    } else if (a->Pieces()==ELEPHAN
               && c->Zoo()->Pieces()==MOUSE
               && a->Colors() != c->Zoo()->Colors())
    {
        ok = false;
    } else if (a->Pieces() >= c->Zoo()->Pieces()
               && a->Colors() != c->Zoo()->Colors())
    {
        ok = true;
    } else
    {
        ok = false;
    }
    return ok;
}

bool RuleRiver::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    if (a->Cells()->Type()==GRASS
            && c->Empty()
            && a->Pieces()==MOUSE)
    {
        ok = true;
    } else if (a->Cells()->Type()==GRASS
               && !c->Empty()
               && a->Pieces()==MOUSE)
    {
        ok = false;
    }
    return (c->Empty() || a->Pieces() == c->Zoo()->Pieces())
            && a->Pieces()==MOUSE
            && ok;
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
