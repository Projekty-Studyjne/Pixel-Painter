#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "mainwindow.h"
#endif // BOARD_H
class Board{
public:
    void createBoard(QGraphicsScene *scene, QGraphicsView *GraphicBoard);
    void undo();
    void open();
    void save();
    void exportToFile();
    void clear();
};
