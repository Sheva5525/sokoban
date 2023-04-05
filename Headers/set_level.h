#ifndef SET_LEVEL_H
#define SET_LEVEL_H

#include <QMainWindow>
#include <QListWidget>
#include "sokoban.h"

namespace Ui {
class set_level;
}

class set_level : public QMainWindow
{
    Q_OBJECT

public:
    explicit set_level(QWidget *parent = nullptr);
    ~set_level();

signals:
    void mWindow();

private slots:


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    sokoban* sWindow;
    Ui::set_level *ui;
    QListWidget* listWidget;
};

#endif // SET_LEVEL_H
