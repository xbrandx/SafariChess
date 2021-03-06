#ifndef ANIMAL_H
#define ANIMAL_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>
#include <QDebug>
#include "game.h"
#include "cell.h"

class Cell;
class Rule;

enum pieces{MOUSE,CAT,DOG,WOLF,CHEETAH,TIGER,LION,ELEPHAN};
enum colors{RED,BLUE};

class Animal : public QLabel
{
public:
    static QImage faces[16];
    static bool initialized;
    int value;
    int x, y;
    pieces piece;
    colors color;
    Cell *cell;
    bool moving;
    static QPoint mouseDownOffset; // Distance to add to mouse pos to move
    static QPoint startDragPos;
    static Qt::MouseButtons buttonDown;

    Animal(int v, QWidget *parent = 0);
//    void resizeEvent(QResizeEvent *);
    pieces Pieces(){return piece;}
    colors Colors(){return color;}
    Cell *Cells(){return cell;}
    static void Initialized();
    void Move(Cell *);
    void ShowZoo();
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    Animal *AdjustPositions(QPoint newPos, QPoint delta);
    void Clear();
};

#endif // ANIMAL_H
