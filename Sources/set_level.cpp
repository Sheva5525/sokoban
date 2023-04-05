#include "Headers\set_level.h"
#include "ui_set_level.h"
#include <QDirIterator>
#include <string>



set_level::set_level(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::set_level)
{
    ui->setupUi(this);
    QStringList LIST_ITEMS;
    QDir dir("maps");
    QStringList nameFilter("*.txt");
    QFileInfoList list = dir.entryInfoList( nameFilter, QDir::Files );
    QFileInfo fileinfo;
    foreach (fileinfo, list) {
         LIST_ITEMS.append(fileinfo.absoluteFilePath().split("/").back().split(".").front());
    }
    ui->listWidget->addItems( LIST_ITEMS );

}

set_level::~set_level()
{
    delete ui;
}

void set_level::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    std::string path = "maps/" + item->text().toStdString() + ".txt";
    sWindow = new sokoban(path);
    connect(sWindow, &sokoban::mWindow, this, &set_level::show);
    sWindow->show();
    this->close();
}

void set_level::on_pushButton_clicked()
{
    this->close();
    emit mWindow();
}
