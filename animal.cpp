#include "animal.h"
#include "cell.h"
#include <QDebug>

QImage Animal::faces[8];
bool Animal::initialized = false;
extern float scale;
QPoint Animal::mouseDownOffset; // Distance to add to mouse pos to move
QPoint Animal::startDragPos;
Qt::MouseButtons Animal::buttonDown;

Animal::Animal(int v, QWidget *parent)
    :QLabel(parent), value(v)
{
    piece = pieces(v % 8);
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
    QString fname =":/animals/M-animal.png";

    int n = 0;
   // for (int j = 1; j <= 2; j++)
 //   {
   //     fname[11] = (char)j;
        for(int i = MOUSE; i <= ELEPHAN; i++)
        {
            fname[10] = piece[i];
            faces[n] = QImage(fname);
            n++;
        }
  //  }
}

void Animal::Move(Cell *to)
{
//    ShowZoo();

    QPoint topLeft = to->pos();

    x = topLeft.x() + 15;
    y = topLeft.y() + 15;

//    resizeEvent(QResizeEvent*);

    to->AcceptAnimal(this);

    move(x, y);
    raise();
    show();
}

void Animal::ShowZoo()
{
    setPixmap(QPixmap::fromImage(faces[value % 8]));

}

void Animal::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "mouse pressed";
    if (ev->button() == Qt::LeftButton)
    {
        startDragPos=pos();
        mouseDownOffset=pos()-ev->globalPos();
//        this->raise();   //raise the object on the top.
    } else if (ev->button() == Qt::RightButton)
    {
        move(pos()+QPoint(0,68));
    }
}

void Animal::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "mouse moved";

    QPoint point =ev->globalPos()+mouseDownOffset;
    QPoint moved = point-pos();

    if(moving)
    //    move(pos()-QPoint(0,68));
        AdjustPositions(point,QPoint(0,10));
    else
        if(moved.manhattanLength()>4)
            // the mouse has moved more than 4 pixel since the oldposition
            moving=true;
}

void Animal::mouseReleaseEvent(QMouseEvent *ev){
    qDebug() << "mouse released";

    if(ev->buttons()) return;
/*    if(popUpCard){
        popUpCard->move(popUpPos);//restore card position
        popUpCard=NULL;
        return;
    }*/
    if(moving /*&& cell*/)
    {
        cell->FindClosestDrop(this, ev->globalPos());
    /*    QPoint drop = this->pos();
        QPoint d = QPoint(25,25);
        int x = drop.x()+25;
        int y = drop.y()+25;

        this->AdjustPositions(QPoint(x,y),ev->globalPos());
*/
    }



/*    else
        if(pile){
            QPoint point =ev->globalPos()+mouseDownOffset;
            QPoint moved =point-pos();
            if(moved.manhattanLength()<=4)
                pile->onClickEvent(this);
        }
    moving=false;
    okToDrag=false;*/
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
