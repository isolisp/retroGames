#include "snaketimer.h"

#define FIRST_DELAY 500

SnakeTimer::SnakeTimer(QObject *parent) : QObject(parent)
{
  delay = FIRST_DELAY;
  timerInit();
}


void SnakeTimer::timerInit(){
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateGraphics()));
  timer->start(delay);
}

void SnakeTimer::startTimer(){
  timer->start(FIRST_DELAY);
}

void SnakeTimer::stopTimer(){
  timer->stop();
}

// SLOTS

void SnakeTimer::updateGraphics(){
  emit move();
}
