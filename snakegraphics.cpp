#include "snakegraphics.h"
#include <QRandomGenerator>
#include "snakegame.h"

#define DIM 40
#define X_POS 0
#define Y_POS 1
#define X_DIR 2
#define Y_DIR 3

#include <qdebug.h>

// VERTIX
Vertix::Vertix(QWidget *parent, int x, int y, QString dir) {
  this->x = x;
  this->y = y;
  this->dir = dir;
}

QString Vertix::getDirection() { return this->dir; }

QPoint Vertix::getPoint() { return QPoint(this->x, this->y); }

// SNAKE CELL

SnakeCell::SnakeCell(QWidget *parent, int pos_x, int pos_y, QString dir) {
  this->x = pos_x;
  this->y = pos_y;
  this->dir = dir;
}

QPoint SnakeCell::getPoint() { return QPoint(this->x, this->y); }

void SnakeCell::setDirection(QString dir) { this->dir = dir; }

SnakeCell::~SnakeCell() { delete this; }

void SnakeCell::generateNewValues() {
  int delta_x = 0;
  int delta_y = 0;

  // Recalculating points...
  if (this->dir == "T") {
    delta_x = 1;
  } else if (this->dir == "B") {
    delta_x = -1;
  } else if (this->dir == "R") {
    delta_y = 1;
  } else {
    delta_y = -1;
  }

  this->x = this->x + delta_x;
  this->y = this->y + delta_y;
}

void SnakeCell::changeDirection(QString dir) { this->dir = dir; }

// SNAKE GRAPHICS

SnakeGraphics::SnakeGraphics(QWidget *parent) : QWidget(parent) {
  pSnakeGame = qobject_cast<SnakeGame *>(parent);
  timer = new SnakeTimer(this);
  timer->startTimer();
  QObject::connect(timer, SIGNAL(move()), this, SLOT(on_move()));

  pSnakeGame->setCellSelected(QPoint(0,0), true);
  pSnakeGame->setCellSelected(QPoint(0,1), true);
  pSnakeGame->setCellSelected(QPoint(0,2), true);

  cells.append(new SnakeCell(this, 0, 0, "R"));
  cells.append(new SnakeCell(this, 0, 1, "R"));
  cells.append(new SnakeCell(this, 0, 2, "R"));
  cells.append(new SnakeCell(this, -1, -1, "R"));
}

SnakeGraphics::~SnakeGraphics() {
  delete this;
  timer->stopTimer();
}

// SLOTS

void SnakeGraphics::on_move() {
  QPoint newPoints[100];
  int delta_x, delta_y, x_pos, y_pos;
  QPoint to_delete;
  SnakeCell *c;
  Vertix *v;

  to_delete = cells.first()->getPoint();
  qDebug() << "toDelete" << to_delete;

  for (int i = 0; !isLatestCell(cells.at(i)); i++) {
    qDebug() << i;
    c = cells.at(i);
    c->generateNewValues();
    for (int j = 0; j < vertixs.size(); j++) {
      *v = vertixs.at(i);
      if ((c->getPoint().x() == v->getPoint().x()) &&
          (c->getPoint().y() == v->getPoint().y()))
        c->setDirection(
            v->getDirection());  // Change the direction of cell in vertix
    }
  }
  qDebug() << "out of for";

  pSnakeGame->setCellSelected(to_delete, false);
  qDebug() << "set false";
  for (int i = 0; !isLatestCell(cells.at(i)); i++) {
    c = cells.at(i);
    pSnakeGame->setCellSelected(c->getPoint(), true);
  }
}

bool SnakeGraphics::isLatestCell(SnakeCell *cell) { return cell->getPoint().x() == -1; }
