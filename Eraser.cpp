#include "Eraser.h"
#include "QDebug"

void Eraser::use(Board &board, QPointF point){
int x,y;
int cell_size=board.getCellSize();
x=point.x()/cell_size;
y=point.y()/cell_size;
int index= (board.getCellsNumber()*x)+y;
QColor color(Qt::white);
unsigned int rgb = color.rgb();
Qt::GlobalColor globalColor = static_cast<Qt::GlobalColor>(rgb);
if(x<board.getCellsNumber() && y < board.getCellsNumber() && index<board.getPointList().size() && point.x() >0 && point.y()> 0){
board.setColor(color, index);
}
}
