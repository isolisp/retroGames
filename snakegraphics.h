#ifndef SNAKEGRAPHICS_H
#define SNAKEGRAPHICS_H

#include <QObject>

class SnakeGraphics : public QObject
{
  Q_OBJECT

public:
  explicit SnakeGraphics(QWidget *parent = nullptr);
  ~SnakeGraphics();

signals:

public slots:
};

#endif // SNAKEGRAPHICS_H
