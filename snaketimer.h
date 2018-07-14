#ifndef SNAKETIMER_H
#define SNAKETIMER_H

#include <QObject>
#include <QTimer>

class SnakeTimer : public QObject {
  Q_OBJECT

  private:
    int delay;
    QTimer* timer;
    void timerInit();

  public:
    explicit SnakeTimer(QObject *parent = nullptr);
    void startTimer();
    void stopTimer();

  signals:
    void move();

  private slots:
    void updateGraphics();

};

#endif  // SNAKETIMER_H
