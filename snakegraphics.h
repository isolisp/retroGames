#ifndef SNAKEGRAPHICS_H
#define SNAKEGRAPHICS_H

#include <QWidget>
#include <QList>
#include "snakegame.h"
#include "snaketimer.h"

class Vertix : QPoint{
  public:
    explicit Vertix(QWidget* parent = nullptr, int x = 0, int y = 0, QString dir = "R");
  private:
    int x, y;
    QString dir;
};

class SnakeCell : public QList<int> {
 public:
  explicit SnakeCell(QWidget* parent = nullptr, int pos_x = 0, int pos_y = 0, QString dir = "R");
  ~SnakeCell();
  QList<QVariant> getValues();
  void applyNewValues(int delta_x, int delta_y);
  void changeDirection(QString dir);


 private:
  int x, y, dir_x;
  QString dir;
};

class SnakeGraphics : public QWidget {
  Q_OBJECT

 private:
  SnakeTimer* timer = Q_NULLPTR;
  SnakeGame* pSnakeGame = Q_NULLPTR;
  QList<SnakeCell> cells;
  QString dir = "R";

 public:
  explicit SnakeGraphics(QWidget* parent = nullptr);
  ~SnakeGraphics();

 private slots:
  void on_move();
  bool isLatestCell(SnakeCell);
};

#endif  // SNAKEGRAPHICS_H
