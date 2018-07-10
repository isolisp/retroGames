#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QWidget>
#include <QObject>

namespace Ui {
    class SnakeGame;
}

class SnakeGame : public QWidget
{
    Q_OBJECT

private:
    void tableInit();
public:
    explicit SnakeGame(QWidget *parent = nullptr);
    Ui::SnakeGame *ui;
    ~SnakeGame();
private slots:
    void on_back_b_clicked();
};

#endif // SNAKEGAME_H
