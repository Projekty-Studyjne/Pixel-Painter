#include <Board.h>

void Board::fillTable(){
    point new_point;
    for(int x=0;x<cellsnumber;x++){
        for( int y=0;y<cellsnumber;y++){
            new_point={x,y,false,Qt::white};
            this->points_list.push_back(new_point);
            }
    }
}

void Board::createBoard(QGraphicsView *GraphicBoard){
    QGraphicsScene *scene=new QGraphicsScene();
    GraphicBoard->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush;
    int window_size=600;
    this->cellsnumber=10;
    cell_size=window_size/cellsnumber;
    for(int wielkosc_x=0; wielkosc_x<cellsnumber; wielkosc_x++){
        for(int wielkosc_y=0; wielkosc_y<cellsnumber; wielkosc_y++){
          QColor color(getColorOfPoint({wielkosc_x, wielkosc_y}));
         scene->addRect(wielkosc_x*cell_size, wielkosc_y*cell_size, cell_size, cell_size, blackpen, color);
        }
    }
}

int Board::getCellSize(){
    return cell_size;
}

int Board::getCellsNumber(){
    return cellsnumber;
}

std::vector<point> Board::getPointList(){
    return points_list;
}

QColor Board::getColorOfPoint(point point){
        QColor color=Qt::white;
        for(int index=0; index<points_list.size(); index++){
            if(point.x==points_list[index].x && point.y==points_list[index].y){
                color=points_list[index].color;
                }
            }
        return color;
}

void Board::setColor(QColor color, int index){
    points_list[index].color = color;
}





