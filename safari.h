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
    Cell *trap[6];
    Cell *base[2];
public:
    Safari(QWidget *par);
    void Load();
};

#endif // SAFARI_H
