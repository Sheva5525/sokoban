#ifndef INFO_H
#define INFO_H

#include <QMainWindow>

namespace Ui {
class info;
}

class info : public QMainWindow
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

signals:
    void mWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::info *ui;
};

#endif // INFO_H
