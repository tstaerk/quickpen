#include "drawscene.h"
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

drawscene::drawscene()
{
    mousereleased=true;
    pencolor=QColor("black");
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
    setSceneRect(0,0,views()[0]->viewport()->width(),views()[0]->viewport()->height());
}

void drawscene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    init();
    QPen pen1=QPen();
    pen1.setWidth(2);
    pen1.setColor(pencolor);
    addLine(mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),pen1);
    qDebug() << "x=" << mouseEvent->scenePos().x();
    oldx=mouseEvent->scenePos().x();
    oldy=mouseEvent->scenePos().y();
    QGraphicsScene::mousePressEvent(mouseEvent);
    mousereleased=false;
}

void drawscene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPen pen1=QPen();
    pen1.setWidth(3);
    pen1.setColor(pencolor);
    if (mousereleased)
    {
        oldx=mouseEvent->scenePos().x();
        oldy=mouseEvent->scenePos().y();
    }
    // the first mouse move event will have the wrong coordinates because the scenerect is not
    // initialized before the first mousepressevent
    static bool firsttime=true;
    if (!firsttime) addLine(oldx,oldy,mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),pen1);
    firsttime=false;
    oldx=mouseEvent->scenePos().x();
    oldy=mouseEvent->scenePos().y();
    QGraphicsScene::mousePressEvent(mouseEvent);
    mousereleased=false;
}
