#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <QMainWindow>
#include "logic.h"
#include <string>

namespace Ui {
class sokoban;
}

class sokoban : public QMainWindow
{
    Q_OBJECT

public:
    explicit sokoban(std::string path, QWidget *parent = nullptr);
    ~sokoban();

signals:
    void mWindow();

private slots:
    void on_action_triggered();

    void on_action3_triggered();

    void on_action2_triggered();

    void slot(QString count);

private:
    std::string _path;
    Ui::sokoban *ui;
    logic* scene;


};

#endif // SOKOBAN_H
