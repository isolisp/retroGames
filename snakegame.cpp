#include <ui_snakegame.h>
#include "snakegame.h"

SnakeGame::SnakeGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SnakeGame)
{
    ui->setupUi(this);
    tableInit();
}

SnakeGame::~SnakeGame(){
    delete ui;
}

void SnakeGame::tableInit(){
    this->ui->fieldsTable->setRowCount(20);
    this->ui->fieldsTable->horizontalHeader()->hide();
    this->ui->fieldsTable->verticalHeader()->hide();
    this->ui->fieldsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->fieldsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->ui->fieldsTable->setShowGrid(true);
}

void SnakeGame::on_back_b_clicked()
{
    delete this;
}
