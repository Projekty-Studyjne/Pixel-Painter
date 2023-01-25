#include "Brush.h"
#include "QDebug"
#include "tests.h"

void Brush::use(Board &board, QPointF point,ColorPalette &colorPalette){
    int x,y;
    int cell_size=board.getCellSize();
    x=point.x()/cell_size;
    y=point.y()/cell_size;
    int index= (board.getCellsNumber()*x)+y;
    QColor color= colorPalette.currentColor();
    if(x<board.getCellsNumber() && y < board.getCellsNumber() && index<board.getPointList().size() && point.x() >0 && point.y()> 0){
    board.setColor(color, index);
    }
//    }
//    for(int i=0;i<board.getPointList().size();i++){
//        qInfo()<<"x: " << board.getPointList()[i].x << "y: " << board.getPointList()[i].y << "color: " << board.getPointList()[i].color.toRgb();
//    }
}
