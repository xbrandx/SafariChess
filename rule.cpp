#include "rule.h"

bool RuleGrass::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
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
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
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
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
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
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
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
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
    return c->Empty() && a->Colors()==BLUE;
}

bool RuleBlueBase::Enforce(Cell *c, Animal *a)
{
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
        qDebug() << "ahh";
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
    return c->Empty() && a->Colors()==RED;
}
