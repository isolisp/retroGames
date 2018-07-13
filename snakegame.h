#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QWidget>
#include <QObject>

#include "snakegraphics.h"

namespace Ui {
    class SnakeGame;
}

class SnakeGame : public QWidget
{
    Q_OBJECT

private:
  void tableInit();
  SnakeGraphics *graphix = Q_NULLPTR;
  QList<QPoint> cellsSelected;
  void setCellSelected(QPoint cell, bool selected);

public:
    explicit SnakeGame(QWidget *parent = nullptr);
    Ui::SnakeGame *ui;
    ~SnakeGame();
    void setSnake(QList<QPoint> list);


private slots:
    void on_back_b_clicked();
};

#endif // SNAKEGAME_H
