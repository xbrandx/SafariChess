#include "animal.h"

QImage Animal::faces[16];
bool Animal::initialized = false;
extern float scale;
QPoint Animal::mouseDownOffset; // Distance to add to mouse pos to move
QPoint Animal::startDragPos;
Qt::MouseButtons Animal::buttonDown;

Animal::Animal(int v, QWidget *parent)
    :QLabel(parent), value(v), cell(0)
{
    piece = pieces(v%8);
    color = colors(v/8);
    ShowZoo();
    show();
}
/*
void Animal::resizeEvent(QResizeEvent *)
{
    ShowZoo();
    move(x * scale, y * scale);
    show();
}
*/
void Animal::Initialized()
{
    if(initialized) return;
    initialized = true;
    char piece[] = {'M','C','D','W','P','T','L','E'}; //P is Cheetah.
    char color[] = {'R','B'};
    QString fname = ":/animals/XX-animal.png";

    int n = 0;
    for(int c = RED; c <= BLUE; c++)
    {
        fname[10] = color[c];
        for(int p = MOUSE; p <= ELEPHAN; p++)
        {
            fname[11] = piece[p];
            faces[n] = QImage(fname);
            n++;
        }
    }
}

void Animal::Move(Cell *to)
{
    QPoint topLeft = to->pos();

    x = topLeft.x() + 11;
    y = topLeft.y() + 11;

//    resizeEvent(QResizeEvent*);

    to->AcceptAnimal(this);

    move(x, y);
    raise();
    show();
}

void Animal::ShowZoo()
{
    setPixmap(QPixmap::fromImage(faces[value % 16]));
}

void Animal::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        startDragPos=pos();
        mouseDownOffset=pos()-ev->globalPos();
    } else if (ev->button() == Qt::RightButton)
    {
        move(pos()+QPoint(0,0));
    }
}

void Animal::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint point =ev->globalPos()+mouseDownOffset;
    QPoint moved = point-pos();

    if(moving)
        AdjustPositions(point,QPoint(0,10));
    else
        if(moved.manhattanLength()>4)
            // the mouse has moved more than 4 pixel since the oldposition
            moving=true;
}

void Animal::mouseReleaseEvent(QMouseEvent *ev){
    if(ev->buttons()) return;
    if(moving)
    {
        cell->FindClosestDrop(this);
    }
}

Animal *Animal::AdjustPositions(QPoint newPos, QPoint delta)
{
    Animal *a = this;
    Animal *top;
    do {
        a->move(newPos);
        a->raise();
        a->show();
        newPos += (delta);
        top = a;
        a->cell = cell;
    }while(!a);
    return top;
}
