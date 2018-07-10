#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QDialog>

namespace Ui {
class SnakeGame;
}

class SnakeGame : public QDialog
{
    Q_OBJECT

public:
    explicit SnakeGame(QWidget *parent = 0);
    ~SnakeGame();

private slots:
    void on_back_b_clicked();

private:
    Ui::SnakeGame *ui;
};

#endif // SNAKEGAME_H
