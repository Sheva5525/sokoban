#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    QString information = "Sokoban (Soko-Ban, яп. 倉庫番, сокобан — кладовщик) — двухмерная компьютерная игра-головоломка, \nв которой игроку необходимо расставить ящики по обозначенным местам лабиринта. \nКладовщик одновременно может двигать только один ящик, толкая вперёд.";
    ui->label->setText(information);
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    this->close();
    emit mWindow();
}
