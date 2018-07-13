#include "snakegraphics.h"
#include "snakegame.h"

#include <qdebug.h>

SnakeGraphics::SnakeGraphics(QWidget *parent) : QWidget(parent)
{
  SnakeGame* pSnakeGame = qobject_cast<SnakeGame*>(parent);

  QPoint points[40];

  points[0] = QPoint(0,0);
  points[1] = QPoint(0,1);
  points[2] = QPoint(0,2);
  points[3] = QPoint(0,3);
  points[4] = QPoint(3,8);
  points[5] = QPoint(-1,-1);

  pSnakeGame->setSnake(points);
}

SnakeGraphics::~SnakeGraphics() { delete this; }
