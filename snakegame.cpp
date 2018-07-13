#include "snakegame.h"
#include <ui_snakegame.h>

#include <QDebug>

#define DIM 40

SnakeGame::SnakeGame(QWidget *parent) : QWidget(parent), ui(new Ui::SnakeGame) {
  ui->setupUi(this);
  tableInit();
  graphix = new SnakeGraphics(this);
}

SnakeGame::~SnakeGame() { delete ui; }

void SnakeGame::tableInit() {
  int i, j;

  // How much units we need?
  int square_h = this->height() / DIM;
  int square_w = this->width() / DIM;

  this->ui->fieldsTable->setRowCount(square_h);
  this->ui->fieldsTable->setColumnCount(square_w);

  // Which dimensions they must to have ?
  this->ui->fieldsTable->verticalHeader()->setDefaultSectionSize(DIM);
  this->ui->fieldsTable->horizontalHeader()->setDefaultSectionSize(DIM);

  // We don't want to see any header nor scrollbar...
  this->ui->fieldsTable->horizontalHeader()->hide();
  this->ui->fieldsTable->verticalHeader()->hide();
  this->ui->fieldsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->ui->fieldsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // Fit the QTable with items

  for (i = 0; i < square_h; i++){
    for (j = 0; j < square_w; j++){
      this->ui->fieldsTable->setItem(i, j, new QTableWidgetItem(0));
    }
  }

  // Grid on and set disable the QTable to can't select any cell
  this->ui->fieldsTable->setShowGrid(true);
  this->ui->fieldsTable->setEnabled(false);
}

void SnakeGame::setSnake(QPoint* list) {
  qDebug() << list[0] << list[1];
  int i = 0;
  while(list[i].rx() != -1){
    setCellSelected(list[i], true);
    i++;
  }
}

void SnakeGame::setCellSelected(QPoint cell, bool selected) {
  if (selected)
    this->ui->fieldsTable->item(cell.rx(), cell.ry())
        ->setBackgroundColor(QColor(Qt::GlobalColor::red));
  else
    this->ui->fieldsTable->item(cell.rx(), cell.ry())
        ->setBackgroundColor(QColor(Qt::GlobalColor::white));
}

// SLOTS
void SnakeGame::on_back_b_clicked() { delete this; }
