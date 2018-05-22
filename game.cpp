#include "animal.h"
#include "cell.h"
#include "game.h"

Game::Game(QWidget *par)
    :parent(par)
{

}

Game::~Game()
{
    //    Clear();
}

void Game::AddCell(Cell *c)
{
    cells.append(c);
}

