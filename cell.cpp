#include "cell.h"

extern float scale;
extern Game *game;
extern QList<Cell *> cells;

Rule *Cell::dropRules[DROPLAST];

Cell::Cell(int x, int y, QWidget *parent)
    :QLabel(parent), X(x), Y(y)
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
    qDebug() << "Accept Me!";

    a->cell = this;
    a->AdjustPositions(pos()+QPoint(11,11),QPoint(0,10));

    qDebug() << this->pos();
}

void Cell::ReleaseAnimal(Animal *a)
{

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
    for (int i = 0; i < NUM; i++)
    {
        if (closest[i] && closest[i]->CanBeDropped(a))
        {
            closest[i]->AcceptAnimal(a);
            return;
        }
    }
//    QPoint p = a->under?(c->under->pos()+c->pile->Delta()/(c->under->faceup?1:2)):c->pile->pos();
//    a->AdjustPositions(p, a->cell->delta); // put them back if no move
}

void Cell::AddDropRules(int n ...)
{
    va_list lp;
    va_start(lp,n);
    int i = 0;
    while(i<n)
        i++;
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

CellRiver::CellRiver(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: rgb(0, 170, 255);"
                  "border:2.5px solid rgb(255, 255, 255);");
}

CellTrap::CellTrap(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: rgb(170, 85, 0);"
                  "border:2.5px solid rgb(255, 255, 255);");
}

CellBase::CellBase(int x, int y, QWidget *parent)
    :Cell(x,y,parent)
{
    setStyleSheet("background-color: red;"
                  "border:2.5px solid rgb(255, 255, 255);");
}
