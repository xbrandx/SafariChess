#include "rule.h"

extern Game *game;

bool RuleGrass::Enforce(Cell *c, Animal *a)
{
    bool ok = true;
    if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[11]
            && c==game->cells[27])
    {
        if (!game->cells[43]->Empty()
                || !game->cells[45]->Empty()
                || !game->cells[47]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[27]
               && c==game->cells[11])
    {
        if (!game->cells[43]->Empty()
                || !game->cells[45]->Empty()
                || !game->cells[47]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[12]
            && c==game->cells[28])
    {
        if (!game->cells[44]->Empty()
                || !game->cells[46]->Empty()
                || !game->cells[48]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[28]
               && c==game->cells[12])
    {
        if (!game->cells[44]->Empty()
                || !game->cells[46]->Empty()
                || !game->cells[48]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[14]
            && c==game->cells[30])
    {
        if (!game->cells[49]->Empty()
                || !game->cells[51]->Empty()
                || !game->cells[53]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[30]
               && c==game->cells[14])
    {
        if (!game->cells[49]->Empty()
                || !game->cells[51]->Empty()
                || !game->cells[53]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[15]
            && c==game->cells[31])
    {
        if (!game->cells[50]->Empty()
                || !game->cells[52]->Empty()
                || !game->cells[54]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[31]
               && c==game->cells[15])
    {
        if (!game->cells[50]->Empty()
                || !game->cells[52]->Empty()
                || !game->cells[54]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[17]
            && c==game->cells[18])
    {
        if (!game->cells[43]->Empty()
                || !game->cells[44]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[18]
               && c==game->cells[17])
    {
        if (!game->cells[43]->Empty()
                || !game->cells[44]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[18]
            && c==game->cells[19])
    {
        if (!game->cells[49]->Empty()
                || !game->cells[50]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[19]
               && c==game->cells[18])
    {
        if (!game->cells[49]->Empty()
                || !game->cells[50]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[20]
            && c==game->cells[21])
    {
        if (!game->cells[45]->Empty()
                || !game->cells[46]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[21]
               && c==game->cells[20])
    {
        if (!game->cells[45]->Empty()
                || !game->cells[46]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[21]
            && c==game->cells[22])
    {
        if (!game->cells[51]->Empty()
                || !game->cells[52]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[22]
               && c==game->cells[21])
    {
        if (!game->cells[51]->Empty()
                || !game->cells[52]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[23]
            && c==game->cells[24])
    {
        if (!game->cells[47]->Empty()
                || !game->cells[48]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[24]
               && c==game->cells[23])
    {
        if (!game->cells[47]->Empty()
                || !game->cells[48]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
            && a->Cells()==game->cells[24]
            && c==game->cells[25])
    {
        if (!game->cells[53]->Empty()
                || !game->cells[54]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    } else if ((a->Pieces()==TIGER || a->Pieces()==LION)
               && a->Cells()==game->cells[25]
               && c==game->cells[24])
    {
        if (!game->cells[53]->Empty()
                || !game->cells[54]->Empty()) return false;
        else if (c->Empty()) return true;
        else if (c->Zoo()->Pieces()>a->Pieces()) return false;
        else if (c->Zoo()->Colors()==a->Colors()) return false;
        else return true;
    }
    QPoint p1 = QPoint (70,70);
    QPoint p2 = QPoint (50,50);
    QPoint p3 = c->pos() - a->Cells()->pos();
    if (p1.x() <= abs(p3.x()) || p1.y() <= abs(p3.y()))
    {
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
        return false;
    } else if (p2.x() <= abs(p3.x()) && p2.y() <= abs(p3.y()))
    {
        return false;
    }
    return c->Empty() && a->Colors()==RED;
}
