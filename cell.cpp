#include <QPainter>
#include "cell.h"
#include "animal.h"
#include "gameboard.h"
#include "game.h"

extern float scale;
extern Game *game;
extern QList<Cell *> cells;

Rule *Cell::dropRules[DROPLAST];

Cell::Cell(int x, int y, QWidget *parent)
    :QLabel(parent), X(x), Y(y)
{
    setStyleSheet("border:2.5px solid rgb(255, 255, 255);");
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
    zoo = a;
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

void Cell::FindClosestDrop(Animal *a, QPoint c)
{
    QPoint drop = a->pos();
//    QPoint d = QPoint(25,25);
    int x = drop.x();
    int y = drop.y();

//    int x = 25;
//    int y = 25;

    a->AdjustPositions(QPoint(x,y),c);

/*    for (int i = 0; i<game->cells.count(); i++)
    {
        b = game->cells[i];
    }
*/
//    a->Move(b);
/*    int i = game->cells.count();
*/

/*    const int NUM = 3;
    QPoint drop = a->pos();
    Cell *closest[NUM] = {NULL, NULL, NULL};
    int distance[NUM] = {10000, 20000, 30000};
        for (int i = 0; i<safari->cell.count(); i++)
        {
            Pile *p = safari->cell[i];
            if (p == c->pile)
                continue;
            QPoint diff = drop - (p->top?p->top->pos():p->pos());
            int dist = diff.manhattanLength();
            for (int j = 0; j < NUM; j++)
            {
                if (dist < distance[j])
                {
                    std::swap(dist, distance[j]);
                    std::swap(p, closest[j]);
                }
            }
        }
        for (int i = 0; i < NUM; i++)
        {
            if (closest[i] && closest[i]->CanBeDropped(c))
            {
                closest[i]->AcceptCards(c);
                return;
            }
        }
        QPoint p = c->under?(c->under->pos()+c->pile->Delta()/(c->under->faceup?1:2)):c->pile->pos();
        c->AdjustPositions(p, c->pile->delta); // put them back if no move
*/
    return;
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
