#include <ui_snakegame.h>
#include "snakegame.h"

#include <QDebug>

#define DIM 40

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
    int i,j;

    // How much units we need?

    int square_h = this->height()/DIM;
    int square_w = this->width()/DIM;

    qDebug() << this->width() << "x" << this->height();
    qDebug() << "hor. " << this->width()/DIM;
    qDebug() << "ver. " << this->height()/DIM;
    qDebug() << square_h << square_w;

    this->ui->fieldsTable->setRowCount(square_h);
    this->ui->fieldsTable->setColumnCount(square_w);

    this->ui->fieldsTable->verticalHeader()->setDefaultSectionSize(DIM);
    this->ui->fieldsTable->horizontalHeader()->setDefaultSectionSize(DIM);

    this->ui->fieldsTable->horizontalHeader()->hide();
    this->ui->fieldsTable->verticalHeader()->hide();
    this->ui->fieldsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->fieldsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for(i=0; i<square_w; i++){
        for(j=0; i<square_h; i++){
            this->ui->fieldsTable->setItem(i,j,new QTableWidgetItem(0));
        }
    }
    this->ui->fieldsTable->setShowGrid(true);
    this->ui->fieldsTable->item(0,0)->setBackgroundColor(QColor(Qt::GlobalColor::red));
    this->ui->fieldsTable->setEnabled(false);


}

void SnakeGame::on_back_b_clicked()
{
    delete this;
}
