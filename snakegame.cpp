#include "snakegame.h"
#include <ui_snakegame.h>

#include <QDebug>

#define DIM 40
#define END_OF_POINTS QPoint(-1, -1)

SnakeGame::SnakeGame(QWidget* parent) : QWidget(parent), ui(new Ui::SnakeGame) {
  ui->setupUi(this);
  tableInit();
}

SnakeGame::~SnakeGame() { delete ui; }

void SnakeGame::tableInit() {
  int i, j;

  // How much units we need?
  square_h = this->height() / DIM;
  square_w = this->width() / DIM;

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

  for (i = 0; i < square_h; i++) {
    for (j = 0; j < square_w; j++) {
      this->ui->fieldsTable->setItem(i, j, new QTableWidgetItem(0));
    }
  }

  // Grid on and set disable the QTable to can't select any cell
  this->ui->fieldsTable->setShowGrid(true);
  this->ui->fieldsTable->setEnabled(false);
}

QList<QPoint> SnakeGame::getSnake() {
  QList<QPoint> points;
  int a = 0;
  for (int i = 0; i < square_h; i++) {
    for (int j = 0; j < square_w; j++) {
      if (this->ui->fieldsTable->item(i, j)->backgroundColor() ==
          QColor(Qt::GlobalColor::red)) {
        if ((feed.x() != i) && (feed.y() != j)) points.append(QPoint(i, j));
      }
    }
  }
  points.append(END_OF_POINTS);
  /*
  for (int i = 0; points[i] != END_OF_POINTS; i++) {
    qDebug() << points[i];
  }
  */
  return points;
}

void SnakeGame::setSnake(QPoint* list) {
  int i = 0;
  while (list[i] != END_OF_POINTS) {
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

void SnakeGame::setFeed(QPoint point) {
  qDebug() << "setFeed" << point;
  this->feed = point;
  setCellSelected(point, true);
}

QPoint SnakeGame::getFeed() { return this->feed; }

QPoint SnakeGame::getScreenDimensions() {
  return QPoint(this->width(), this->height());
}

// SLOTS
void SnakeGame::on_back_b_clicked() { delete this; }
