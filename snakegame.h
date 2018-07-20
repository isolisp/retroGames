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
  void setFeed(QPoint point);
  void setCellSelected(QPoint cell, bool selected);
  QPoint getScreenDimensions();
  int getVerticalSquares();
  int getHorizontalSquares();


 private slots:
  void on_back_b_clicked();
};

#endif  // SNAKEGAME_H
