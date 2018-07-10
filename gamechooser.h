#ifndef GAMECHOOSER_H
#define GAMECHOOSER_H

#include <QMainWindow>
#include <snakegame.h>

namespace Ui {
    class GameChooser;
}

class GameChooser : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameChooser(QWidget *parent = 0);
    ~GameChooser();

private slots:
    void on_snake_b_clicked();

private:
    Ui::GameChooser *ui;

    SnakeGame *snakegame = Q_NULLPTR;

};

#endif // GAMECHOOSER_H
