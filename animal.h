#ifndef ANIMAL_H
#define ANIMAL_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>

class Cell;
enum pieces{MOUSE, CAT, DOG, WOLF, CHEETAH, TIGER, LION, ELEPHAN};

class Animal: public QLabel
{
public:
    static QImage faces[8];
    static bool initialized;
    int value;
    int x, y;
    pieces piece;
    Cell *cell;
    bool moving;
    static QPoint mouseDownOffset; // Distance to add to mouse pos to move
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown;
public:
    Animal(int v, QWidget *parent = 0);
//    void resizeEvent(QResizeEvent *);
    void Move(Cell *);
    void ShowZoo();
    pieces Pieces(){return piece;}

    static void Initialized();

    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    Animal *AdjustPositions(QPoint newPos, QPoint delta);
};

#endif // ANIMAL_H
