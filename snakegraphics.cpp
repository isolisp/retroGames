#include "snakegraphics.h"
#include "snakegame.h"
#include <QRandomGenerator>

#define DIM 40

#include <qdebug.h>

SnakeGraphics::SnakeGraphics(QWidget* parent) : QWidget(parent) {
  pSnakeGame = qobject_cast<SnakeGame*>(parent);
  timer = new SnakeTimer(this);
  timer->startTimer();
  QPoint points[40];
  QObject::connect(timer, SIGNAL(move()), this, SLOT(on_move()));

  points[0] = QPoint(0, 0);
  points[1] = QPoint(0, 1);
  points[2] = QPoint(0, 2);
  points[3] = QPoint(0, 3);
  points[5] = END_OF_POINTS;

  pSnakeGame->setSnake(points);

  generateNewFeed();
}

SnakeGraphics::~SnakeGraphics() {
  delete this;
  timer->stopTimer();
}

bool SnakeGraphics::newRandomInSnake(int x, int y){
  QList<QPoint> selectedPoints = pSnakeGame->getSnake();
  for(int i=0; selectedPoints[i] != END_OF_POINTS; i++){
    if((selectedPoints[i].x() == x) && (selectedPoints[i].y() == y)) return true;
  }
  return false;
}

void SnakeGraphics::generateNewFeed(){
  QRandomGenerator *rand = new QRandomGenerator();

  QPoint dimension = pSnakeGame->getScreenDimensions();

  int square_h = dimension.x() / DIM;
  int square_w = dimension.y() / DIM;

  qDebug() << square_h << square_w;

  int new_x = rand->bounded(0,square_h);
  int new_y = rand->bounded(0,square_w);

  while(newRandomInSnake(new_x, new_y)){
    int new_x = rand->bounded(0,square_h);
    int new_y = rand->bounded(0,square_w);
  }

  qDebug() << new_x << new_y;

  pSnakeGame->setFeed(QPoint(new_x, new_y));
}
// SLOTS

void SnakeGraphics::on_move() {
  qDebug() << "move";
  QPoint newPoints[100];
  QList<QPoint> selectedPoints = pSnakeGame->getSnake();

  int delta_x = 0;
  int delta_y = 0;
  int x_pos,y_pos;

  // Recalculating points...
  if(dir == "T"){
    delta_x = 1;
  }
  else if(dir == "B"){
    delta_x = -1;
  }
  else if(dir == "R"){
    delta_y = 1;
  }
  else{
    delta_y = -1;
  }

  int i = 1;
  while(selectedPoints.at(i) != END_OF_POINTS){
    x_pos = selectedPoints.at(i).x();
    y_pos = selectedPoints.at(i).y();
    newPoints[i] = QPoint((x_pos+delta_x),(y_pos+delta_y));
    i++;
  }
  newPoints[++i] = END_OF_POINTS;

  pSnakeGame->setSnake(newPoints);
}
