#pragma once
#ifndef ERASER_H
#define ERASER_H

#endif // ERASER_H
#include "Tool.h"

class Eraser : public Tool{
    QGraphicsScene *scene = new QGraphicsScene();
    Board *board;
public:
    void use(Board &board, QPointF point,ColorPalette &colorPalette);
};
