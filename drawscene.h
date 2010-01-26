#ifndef DRAWSCENE_H
#define DRAWSCENE_H

#include <QGraphicsScene>

class drawscene : public QGraphicsScene
{
public:
    drawscene();

    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    int oldx,oldy;
    bool mousereleased;
};

#endif // DRAWSCENE_H
