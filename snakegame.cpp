#include <ui_snakegame.h>
#include "snakegame.h"

#define ROWS 80
#define COLUMNS 80

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

    this->ui->fieldsTable->setRowCount(ROWS);
    this->ui->fieldsTable->setColumnCount(COLUMNS);
    this->ui->fieldsTable->horizontalHeader()->hide();
    this->ui->fieldsTable->verticalHeader()->hide();
    this->ui->fieldsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->fieldsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->fieldsTable->setShowGrid(true);

    for(i=0; i<COLUMNS; i++){
        for(j=0; i<ROWS; i++){
            this->ui->fieldsTable->setItem(i,j,new QTableWidgetItem(0));
        }
    }
    this->ui->fieldsTable->resizeColumnsToContents();
    this->ui->fieldsTable->resizeRowsToContents();

    this->ui->fieldsTable->item(0,0)->setBackgroundColor(QColor(Qt::GlobalColor::red));

    this->ui->fieldsTable->setEnabled(false);


}

void SnakeGame::on_back_b_clicked()
{
    delete this;
}
