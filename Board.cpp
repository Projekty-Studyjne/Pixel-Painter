#include <Board.h>

void Board::createBoard(QGraphicsScene *scene, QGraphicsView *GraphicBoard){
    scene = new QGraphicsScene(GraphicBoard);
    ui->Board->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush(QColor(90, 208, 184, 150));
    int wielkosc_okna=400;
    punkt pkt;
    int cell_size=wielkosc_okna/gra.getMax();
    ui->Board->setMaximumSize(wielkosc_okna+gra.getMax(),wielkosc_okna+gra.getMax());
    ui->Board->setMinimumSize(wielkosc_okna+gra.getMax(),wielkosc_okna+gra.getMax());
    for(int wielkosc_x=0; wielkosc_x<ui->board_size->value(); wielkosc_x++){
        pkt.x = wielkosc_x;
        for(int wielkosc_y=0; wielkosc_y<ui->board_size->value(); wielkosc_y++){
            pkt.y=wielkosc_y;
            if(gra.getIsAlive({pkt.x,pkt.y})){
                square = scene->addRect(cell_size*wielkosc_x, cell_size*wielkosc_y, cell_size, cell_size, blackpen, brush);
            }
            else{
                square = scene->addRect(cell_size*wielkosc_x, cell_size*wielkosc_y, cell_size, cell_size, blackpen);
                }
            }
        }

    }
