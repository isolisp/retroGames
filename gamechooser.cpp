#include <gamechooser.h>
#include "ui_gamechooser.h"


GameChooser::GameChooser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameChooser)
{
    ui->setupUi(this);
}

GameChooser::~GameChooser()
{
    delete ui;
}

void GameChooser::on_snake_b_clicked()
{
    snakegame = new SnakeGame();
    snakegame->setGeometry(this->x(), this->y(), 800, 600);
    snakegame->show();
}
