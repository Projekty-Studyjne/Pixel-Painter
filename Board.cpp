#include <Board.h>

void Board::fillTable(){
    points_list.clear();
    point new_point;
    for(int x=0;x<cellsNumber;x++){
        for( int y=0;y<cellsNumber;y++){
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
    cellSize=window_size/cellsNumber;
    setCellSize(cellSize);
    for(int wielkosc_x=0; wielkosc_x<cellsNumber; wielkosc_x++){
        for(int wielkosc_y=0; wielkosc_y<cellsNumber; wielkosc_y++){
          QColor color(getColorOfPoint({wielkosc_x, wielkosc_y}));
         scene->addRect(wielkosc_x*cellSize, wielkosc_y*cellSize, cellSize, cellSize, blackpen, color);
        }
    }
}

int Board::getCellSize(){
    return cellSize;
}

int Board::getCellsNumber(){
    return cellsNumber;
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

void Board::setCellsNumber(int cellsnumber){
    this->cellsNumber=cellsnumber;
    fillTable();
}

void Board::setCellSize(int cellsize){
    this->cellSize=cellSize;
}



