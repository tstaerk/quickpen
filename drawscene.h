#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>

class drawscene : public QGraphicsScene
{
public:
    drawscene();
    void init();
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    int oldx,oldy;
    bool mousereleased;
};

#endif // DRAWSCENE_H
