#include "snakegame.h"
#include "ui_snakegame.h"

SnakeGame::SnakeGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SnakeGame)
{

    ui->setupUi(this);
}

SnakeGame::~SnakeGame()
{
    delete ui;
}

void SnakeGame::on_back_b_clicked()
{
    delete this;
}
