#include "Brush.h"
#include "QDebug"
#include "tests.h"

void Brush::use(vector<point> list, QPointF point){
    int x,y;
//    int cell_size=board->getCellSize();
    x=point.x()/60;
    y=point.y()/60;
    int index= (10*x)+y;
    list[index].color=Qt::red;
//    for(int i=0;i<list.size();i++){
//        qInfo()<<"x: " << list[i].x << "y: " << list[i].y << "color: " << list[i].color.toRgb();
//    }
}
