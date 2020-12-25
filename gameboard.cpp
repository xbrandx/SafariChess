#include "animal.h"
#include "cell.h"
#include "safari.h"
#include "game.h"
#include "gameboard.h"
#include "ui_gameboard.h"

Game *game;
float scale = 1.0;

GameBoard::GameBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    resize(300,300);
    Animal::Initialized();
    game = NULL;
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_actionNew_triggered()
{
    resize(490,650);
    game = new Safari(ui->centralWidget);
    game->Load();
}

void GameBoard::resizeEvent(QResizeEvent *)
{
    scale = qMin(width()/(490.0), height()/(650.0));
    ui->centralWidget->resize(scale * 490, scale * 650);
}

