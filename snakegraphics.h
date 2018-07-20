#ifndef SNAKEGRAPHICS_H
#define SNAKEGRAPHICS_H

#include <QWidget>
#include <QList>
#include "snakegame.h"
#include "snaketimer.h"

class Vertix : QPoint{
  public:
    explicit Vertix(QWidget* parent = nullptr, int x = 0, int y = 0, QString dir = "R");
    QString getDirection();
    QPoint getPoint();

  private:
    int x, y;
    QString dir;
};

class SnakeCell : public QList<int> {
 public:
  explicit SnakeCell(QWidget* parent = nullptr, int pos_x = 0, int pos_y = 0, QString dir = "R");
  ~SnakeCell();
  QPoint getPoint();
  void setDirection(QString dir);
  void generateNewValues();
  void changeDirection(QString dir);

private:
  int x, y, dir_x;
  QString dir;
};

class SnakeGraphics : public QWidget {
  Q_OBJECT

 private:
  bool isLatestCell(SnakeCell *cell);
  SnakeTimer* timer = Q_NULLPTR;
  SnakeGame* pSnakeGame = Q_NULLPTR;
  QList<SnakeCell*> cells;
  QList<Vertix> vertixs;
  QString dir = "R";

 public:
  explicit SnakeGraphics(QWidget* parent = nullptr);
  ~SnakeGraphics();
  int square_v;
  int square_w;

 private slots:
  void on_move();
};

#endif  // SNAKEGRAPHICS_H
