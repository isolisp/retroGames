#include "mainwindow.h"
#include "ui_gamechooser.h"
#include "ui_snakegame.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_snake_b_clicked()
{
    snakegame = new SnakeGame(this);
    snakegame->show();
}
