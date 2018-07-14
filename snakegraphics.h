#ifndef SNAKEGRAPHICS_H
#define SNAKEGRAPHICS_H

#include <QWidget>
#include "snaketimer.h"
#include "snakegame.h"

#define END_OF_POINTS QPoint(-1,-1)

class SnakeGraphics : public QWidget
{
  Q_OBJECT

  private:
    SnakeTimer* timer = Q_NULLPTR;
    SnakeGame* pSnakeGame = Q_NULLPTR;

    QString dir = "R";

    void generateNewFeed();
    bool newRandomInSnake(int x, int y);

  public:
    explicit SnakeGraphics(QWidget *parent = nullptr);
    ~SnakeGraphics();

  private slots:
    void on_move();
};

#endif // SNAKEGRAPHICS_H
