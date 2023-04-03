#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    sWindow = new set_level();
    connect(sWindow, &set_level::mWindow, this, &MainWindow::show);
    iWindow = new info();
    connect(iWindow, &info::mWindow, this, &MainWindow::show);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    sWindow->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    iWindow->show();
    this->close();
}
