#include "Headers\sokoban.h"
#include "ui_sokoban.h"
#include "Headers\logic.h"
#include <QMessageBox>

sokoban::sokoban(std::string path, QWidget *parent) :
    QMainWindow(parent),
    _path(path),
    ui(new Ui::sokoban)
{
    resize(800,600);
    showMaximized();
    ui->setupUi(this);
    ui->label->setText("");
    scene = new logic(path);
    connect(scene, SIGNAL(ndGame(QString)), this, SLOT(slot(QString)));
    ui->graphicsView->setScene(scene);
    scene->setLabel(ui->label);
    ui->graphicsView->setFocus();
}

sokoban::~sokoban()
{
    delete ui;
}

void sokoban::on_action_triggered()
{
    close();
}

void sokoban::on_action3_triggered()
{
    scene = new logic(_path);
    ui->graphicsView->setScene(scene);
    scene->setLabel(ui->label);
    connect(scene, SIGNAL(ndGame(QString)), this, SLOT(slot(QString)));
}

void sokoban::slot(QString count) {
    QMessageBox::about(this, QString("Победа"), QString("Уровень пройден\nВсего шагов: ") + count);
    emit mWindow();
    close();
}

void sokoban::on_action2_triggered()
{
    emit mWindow();
    this->close();
}
