#include "Brush.h"
#include "QDebug"
#include "tests.h"

void Brush::use(Board &board, QPointF point){
    int x,y;
    //int cell_size=board->getCellSize();
    x=point.x()/60;
    y=point.y()/60;
    int index= (10*x)+y;
    QColor color(Qt::blue);
    unsigned int rgb = color.rgb();
    Qt::GlobalColor globalColor = static_cast<Qt::GlobalColor>(rgb);
   board.setColor(color, index);
    for(int i=0;i<board.getPointList().size();i++){
        qInfo()<<"x: " << board.getPointList()[i].x << "y: " << board.getPointList()[i].y << "color: " << board.getPointList()[i].color.toRgb();
    }
}
