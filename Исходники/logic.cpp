#include <QGraphicsItem>
#include "logic.h"
#include <QKeyEvent>
#include <fstream>
#include <string>
#include <QLabel>
#include <QString>
#include <QMessageBox>

logic::logic(std::string path, QObject *parent) : QGraphicsScene(parent) {
    QBrush brushActiveWall(QColor(255, 255, 255), QPixmap(":/res/block_05.png"));
    QBrush brushDisableWall(QColor(255, 255, 255), QPixmap(":/res/block_05.png"));
    brushPlayer = new QBrush(QColor(255, 255, 255), QPixmap(":/res/player_20.png"));
    brushPlayer1 = new QBrush(QColor(255, 255, 255), QPixmap(":/res/player_02.png"));
    brushPlayer2 = new QBrush(QColor(255, 255, 255), QPixmap(":/res/player_11.png"));
    brushPlayer3 = new QBrush(QColor(255, 255, 255), QPixmap(":/res/player_23.png"));
    _Box = new QBrush(QColor(255, 255, 255), QPixmap(":/res/crate_02.png"));
    _activeBox = new QBrush(QColor(0, 125, 0), QPixmap(":/res/crate_02.png"));
    setBackgroundBrush(QBrush(QColor(255,255,255), QPixmap(":/res/bg.jpg")));
    drawMap(path);

}

void logic::drawMap(std::string path) {

    std::ifstream file(path);
    std::string str;
    int _h = 0;
    QBrush brushWall(QColor(255, 255, 255), QPixmap(":/res/block_05.png"));
    QBrush brushPoint(QColor(255, 255, 255), QPixmap(":/res/crate_27.png"));
    QPen pen(Qt::NoPen);
    while(getline(file, str)) {
        for (size_t i = 0; i < str.size(); i++) {
            if ((str[i] == 'w') || (str[i] == 'W')) {
                QGraphicsItem* item = addRect(QRectF(i * 64, _h * 64, 63.5, 63.5), pen, brushWall);
                item->setData(0, "Wall");
            }

            if (str[i] == 'b') {
                placeBox(i * 64, _h * 64);
            }

            if (str[i] == 'p') {
                _player = addRect(QRectF(i * 64, _h * 64, 63, 63), pen, *brushPlayer3);
                _player->setData(0, "player");
            }

            if (str[i] == 'o') {
                QGraphicsItem* point = addRect(QRectF(i * 64, _h * 64, 63, 63), pen, brushPoint);
                point->setData(1, "point");
                point->setZValue(-1);
                pointCount++;
            }
        }
        _h++;
    }
}

QGraphicsItem* logic::chekCollision(QGraphicsItem * item) {
    QList<QGraphicsItem *> collisions = collidingItems(item);

    foreach (QGraphicsItem* it, collisions) {
        if ((it == item) || (it->zValue() == -1)) continue;
        return it;
    }
    return NULL;
}

void logic::placeBox(float x, float y) {
    QGraphicsRectItem* box = addRect(QRectF(x, y, 63, 63), QPen(Qt::NoPen), *_Box);
    if (chekCollision(box))
        removeItem(box);
    else
        box->setData(0, "Box");
}

void logic::keyPressEvent(QKeyEvent * keyEvent) {
    QPointF np;
    np.setX(0);
    np.setY(0);
    switch (keyEvent->key()) {
            case Qt::Key_Left:
                np.setX(-64);
                _player->setBrush(*brushPlayer);
                break;
            case Qt::Key_Right:
                np.setX(64);
                _player->setBrush(*brushPlayer2);
                break;
            case Qt::Key_Up:
                np.setY(-64);
                _player->setBrush(*brushPlayer1);
                break;
            case Qt::Key_Down:
                np.setY(64);
                _player->setBrush(*brushPlayer3);
                break;
    }

    _player->moveBy(np.x(), np.y());
    QGraphicsItem* obstacle = chekCollision(_player);
    if (obstacle) {
        if (obstacle->data(0) == "Wall") {
            _player->moveBy(-np.x(), -np.y());
            _player->setBrush(*brushPlayer3);
            return;
        } else
        if (obstacle->data(0) == "Box") {
            obstacle->moveBy(np.x(), np.y());
            if (chekCollision(obstacle) || chekCollision(_player)) {
                obstacle->moveBy(-np.x(), -np.y());
                _player->moveBy(-np.x(), -np.y());
                _player->setBrush(*brushPlayer3);
                return;
            }
        }
    }
    steps++;
    QString str = QString::number(steps);
    _label->setText(QString("Количество шагов: ") + str);
    win();
}

void logic::setLabel(QLabel* label) {
    _label = label;
    QString str = QString::number(steps);
    _label->setText(QString("Количество шагов: ") + str);
}

void logic::win() {
    QList<QGraphicsItem*> list = items();
    int count = 0;
    foreach (QGraphicsItem* item, list) {
        if (item->data(0) == "Box") {
            QList<QGraphicsItem *> collisions = collidingItems(item);
            if (collisions.size() == 1)  {
                count++;
            }
        }
    }
    if (pointCount == count) {
        QString str = QString::number(steps);
        emit ndGame(str);
    }
}


