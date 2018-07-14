#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QObject>
#include <QWidget>

namespace Ui {
class SnakeGame;
}

class SnakeGame : public QWidget {
  Q_OBJECT

 private:
  void tableInit();
  int square_w, square_h;
  QPoint feed;

 public:
  explicit SnakeGame(QWidget *parent = nullptr);
  Ui::SnakeGame *ui;
  ~SnakeGame();
  void setSnake(QPoint *list);
  QList<QPoint> getSnake();
  void setCellSelected(QPoint cell, bool selected);
  void setFeed(QPoint point);
  QPoint getFeed();
  QPoint getScreenDimensions();

 private slots:
  void on_back_b_clicked();
};

#endif  // SNAKEGAME_H
