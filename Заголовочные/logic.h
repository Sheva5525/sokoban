#ifndef LOGIC_H
#define LOGIC_H
#include <QGraphicsScene>
#include <QLabel>

class logic : public QGraphicsScene {
    Q_OBJECT
    public:
        logic(std::string path, QObject *parent = 0);
        void drawMap(std::string path);
        QGraphicsItem* chekCollision(QGraphicsItem* item);
        void placeBox(float x, float y);
        void chekPoint(QGraphicsItem * box);
        void setLabel(QLabel* label);
        void win();
    protected:
        virtual void keyPressEvent(QKeyEvent * keyEvent);
    signals:
        void ndGame(QString count);
    private:
        QGraphicsScene* _scene;
        QGraphicsRectItem* _player;
        QBrush* _lastBrush;
        QBrush* brushPlayer;
        QBrush* brushPlayer1;
        QBrush* brushPlayer2;
        QBrush* brushPlayer3;
        QBrush* _activeBox;
        QBrush* _Box;
        int steps = 0;
        QLabel* _label;
        int pointCount = 0;
};

#endif // LOGIC_H
