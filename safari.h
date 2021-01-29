#ifndef SAFARI_H
#define SAFARI_H266

#include <QWidget>
#include "game.h"
#include "cell.h"
#include "animal.h"

class Cell;

class Safari : public Game
{
public:
    Cell *grass[43];
    Cell *river[12];
    Cell *red_trap[3];
    Cell *blue_trap[3];
    Cell *red_base;
    Cell *blue_base;

    Safari(QWidget *par);
    void Load();
};

#endif // SAFARI_H
