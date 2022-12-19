#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "QGraphicsView"

#endif // BOARD_H
class Board{
private:
    int cellsnumber=10;
public:
    Board(){}
    void createBoard(QGraphicsView *GraphicBoard);
    void undo();
    void open();
    void save();
    void exportToFile();
    void clear();
};
