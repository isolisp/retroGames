#include "snakegraphics.h"
#include "snakegame.h"

SnakeGraphics::SnakeGraphics(QWidget *parent) : QObject(parent)
{
  SnakeGame* pSnakeGame = qobject_cast<SnakeGame*>(parent);
  QList<QPoint> points;
  points.append(QPoint(0,0));
  points.append(QPoint(0,1));
  points.append(QPoint(0,2));
  points.append(QPoint(0,3));
  points.append(QPoint(0,4));
  pSnakeGame->setSnake(points);
}

SnakeGraphics::~SnakeGraphics() { delete this; }
