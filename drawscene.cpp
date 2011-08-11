#include "drawscene.h"
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

drawscene::drawscene()
{
    mousereleased=true;
    setBackgroundBrush(Qt::white);  // the N900 has a black background by default
}

void drawscene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
// Do not remove this function, it is needed for maemo 4's QT.
{
    mousereleased=true;
}

void drawscene::init()
{
    static bool everdone=false;
    if (everdone) return;
    everdone=true;
    qDebug() << "scenerect=" << sceneRect();
    setSceneRect(0,0,views()[0]->viewport()->width(),views()[0]->viewport()->height());
}

void drawscene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPen pen1=QPen();
    pen1.setWidth(2);
    addLine(mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),pen1);
    qDebug() << "x=" << mouseEvent->scenePos().x();
    init();
    oldx=mouseEvent->scenePos().x();
    oldy=mouseEvent->scenePos().y();
    QGraphicsScene::mousePressEvent(mouseEvent);
    mousereleased=false;
}

void drawscene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPen pen1=QPen();
    pen1.setWidth(3);
    if (mousereleased)
    {
        oldx=mouseEvent->scenePos().x();
        oldy=mouseEvent->scenePos().y();
    }
    addLine(oldx,oldy,mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),pen1);
    qDebug() << "x=" << mouseEvent->scenePos().x();
    oldx=mouseEvent->scenePos().x();
    oldy=mouseEvent->scenePos().y();
    QGraphicsScene::mousePressEvent(mouseEvent);
    mousereleased=false;
}
