#ifndef SNAKETIMER_H
#define SNAKETIMER_H

#include <QObject>

class SnakeTimer : public QObject
{
  Q_OBJECT
public:
  explicit SnakeTimer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SNAKETIMER_H