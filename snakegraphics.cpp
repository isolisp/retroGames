#include "snakegraphics.h"
#include <QRandomGenerator>
#include "snakegame.h"

#define DIM 40
#define X_POS 0
#define Y_POS 1
#define X_DIR 2
#define Y_DIR 3

#include <qdebug.h>

Vertix::Vertix(QWidget *parent, int x, int y, QString dir) {
  this->x = x;
  this->y = y;
  this->dir = dir;
}

SnakeCell::SnakeCell(QWidget *parent, int pos_x, int pos_y, QString dir) {
  this->x = pos_x;
  this->y = pos_y;
  this->dir = dir;
}

QList<QVariant> SnakeCell::getValues() {
  return QList<QVariant>() << this->x << this->y << this->dir;
}

SnakeCell::~SnakeCell() { delete this; }

void SnakeCell::applyNewValues(int delta_x, int delta_y) {
  this->x = this->x + delta_x;
  this->y = this->y + delta_y;
}

void SnakeCell::changeDirection(QString dir) { this->dir = dir; }

SnakeGraphics::SnakeGraphics(QWidget *parent) : QWidget(parent) {
  pSnakeGame = qobject_cast<SnakeGame *>(parent);
  timer = new SnakeTimer(this);
  timer->startTimer();
  QObject::connect(timer, SIGNAL(move()), this, SLOT(on_move()));

  cells.append(SnakeCell(this, 0, 0, "R"));
  cells.append(SnakeCell(this, 0, 1, "R"));
  cells.append(SnakeCell(this, -1, -1, "R"));
}

SnakeGraphics::~SnakeGraphics() {
  delete this;
  timer->stopTimer();
}

// SLOTS

void SnakeGraphics::on_move() {
  QPoint newPoints[100];
  int delta_x, delta_y, x_pos, y_pos, x_to_del, y_to_del;

  delta_x = 0;
  delta_y = 0;

  x_to_del = cells.first().at(0);
  y_to_del = cells.first().at(1);

  // Recalculating points...
  if (dir == "T") {
    delta_x = 1;
  } else if (dir == "B") {
    delta_x = -1;
  } else if (dir == "R") {
    delta_y = 1;
  } else {
    delta_y = -1;
  }

  for (int i = 0; !isLatestCell(cells.at(i)); i++) {
  }
}

bool SnakeGraphics::isLatestCell(SnakeCell cell) { return cell.at(0) == -1; }
