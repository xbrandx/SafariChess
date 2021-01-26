#include "cell.h"

extern float scale;
extern Game *game;
extern QList<Cell *> cells;

Rule *CellGrass::dropRules[DROPLAST];
Rule *CellRiver::dropRules[DROPLAST];
Rule *CellTrap::dropRules[DROPLAST];
Rule *CellRedBase::dropRules[DROPLAST];
Rule *CellBlueBase::dropRules[DROPLAST];

Cell::Cell(int x, int y, QWidget *parent)
    :QLabel(parent), zoo(0), X(x), Y(y)
{
    setStyleSheet("border:2.5px solid rgb(255, 255, 255);");
    game->AddCell(this);
    move(x, y);
    resize(70, 70);
//    setFrameShape(Box);
//    setLineWidth(2);
    show();
}
/*
void Cell::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    resize(70 * scale, 70 * scale);
    p.scale(scale, scale);
    move(X * scale, Y * scale);
    p.setRenderHint(QPainter::Antialiasing);
}
*/
void Cell::AcceptAnimal(Animal *a)
{
    if (a == NULL) return;
    if (a->cell)
    {
        a->cell->ReleaseAnimal(a);
    }

    zoo = a;

    a->cell = this;
    a->AdjustPositions(pos()+QPoint(11,11),QPoint(0,10));

    if (Type() == RED_BASE && a->Colors() == BLUE)
    {
        QMessageBox msgBox;
        msgBox.setText("Blue wins!");
        msgBox.exec();
    }

    if (Type() == BLUE_BASE && a->Colors() == RED)
    {
        QMessageBox msgBox;
        msgBox.setText("Red wins!");
        msgBox.exec();
    }
}

void Cell::ReleaseAnimal(Animal *a)
{
    a->cell->zoo = NULL;
}

bool Cell::CanBeDropped(Animal *a)
{
    int i = 0;
    bool ok=true;
    while(ok&&DropRule(i)){
        ok=DropRule(i++)->Enforce(this, a);
    }
    return ok;
}

void Cell::FindClosestDrop(Animal *a)
{
    const int NUM = 3;
    QPoint drop = a->pos();
    Cell *closest[NUM] = {NULL, NULL, NULL};
    int distance[NUM] = {10000, 20000, 30000};
    for (int i = 0; i<game->cells.count(); i++)
    {
        Cell *c = game->cells[i];
        if (c == a->cell)
            continue;
        QPoint diff = drop - c->pos();
        int dist = diff.manhattanLength();
        for (int j = 0; j < NUM; j++)
        {
            if (dist < distance[j])
            {
                std::swap(dist, distance[j]);
                std::swap(c, closest[j]);
            }
        }
    }
    for (int i = 0; i < NUM - 2; i++)
    {
        if (closest[i] && closest[i]->CanBeDropped(a))
        {
            closest[i]->AcceptAnimal(a);
            return;
        }
    }
    QPoint p = a->cell->pos() + QPoint(11,11);
    a->AdjustPositions(p, QPoint(0,10)); // put them back if no move
}

void Cell::AddDropRules(int n ...)
{
    va_list lp;
    va_start(lp,n);
    int i = 0;
    while(i<n)
        DropRule(i++,va_arg(lp,Rule*));
    DropRule(i,NULL);
    va_end(lp);
}


//Methods for inheriting classes----------------------------------------
CellGrass::CellGrass(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: rgb(0, 170, 0);"
                  "border:2.5px solid rgb(255, 255, 255);");
}

cellType CellGrass::Type()
{
    return GRASS;
}

CellRiver::CellRiver(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: rgb(0, 170, 255);"
                  "border:2.5px solid rgb(255, 255, 255);");
}

cellType CellRiver::Type()
{
    return RIVER;
}

CellTrap::CellTrap(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: rgb(170, 85, 0);"
                  "border:2.5px solid rgb(255, 255, 255);");
}

cellType CellTrap::Type()
{
    return TRAP;
}

CellRedBase::CellRedBase(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: red;"
                  "border:2.5px solid rgb(255, 255, 255);");
}

cellType CellRedBase::Type()
{
    return RED_BASE;
}

CellBlueBase::CellBlueBase(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: red;"
                  "border:2.5px solid rgb(255, 255, 255);");
}

cellType CellBlueBase::Type()
{
    return BLUE_BASE;
}
