#ifndef BRUSH_H
#define BRUSH_H

#endif // BRUSH_H
#include "Tool.h"
#include <QPoint>
#include <QCursor>
#include "QGraphicsScene"

class Brush : public Tool{
    QGraphicsScene *scene = new QGraphicsScene();

public:
    void use(QPointF point) override;
};
