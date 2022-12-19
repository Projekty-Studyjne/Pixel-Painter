#include <Board.h>

void Board::createBoard(QGraphicsView *GraphicBoard){
    QGraphicsScene *scene=new QGraphicsScene();
    GraphicBoard->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush(Qt::white);
    cellsnumber=24;
    int window_size=600;
    int cell_size=window_size/cellsnumber;
    for(int wielkosc_x=0; wielkosc_x<cellsnumber; wielkosc_x++){
        for(int wielkosc_y=0; wielkosc_y<cellsnumber; wielkosc_y++){
         scene->addRect(wielkosc_x*cell_size, wielkosc_y*cell_size, cell_size, cell_size, blackpen, brush);
        }
    }
}
