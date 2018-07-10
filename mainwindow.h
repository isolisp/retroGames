#ifndef GAMECHOOSER_H
#define GAMECHOOSER_H

#include <QMainWindow>
#include <snakegame.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_snake_b_clicked();

private:
    Ui::MainWindow *ui;

    SnakeGame *snakegame = Q_NULLPTR;

};

#endif // GAMECHOOSER_H
