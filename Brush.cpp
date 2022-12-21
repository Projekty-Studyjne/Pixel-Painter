#include "Brush.h"
#include "QDebug"

void Brush::use(QPointF point){
    int x,y;
    int cell_size=board->getCellSize();
    x=point.x()/cell_size;
    y=point.y()/cell_size;
    board->getColorOfPoint({x,y});
//    board->getPointList().
}
