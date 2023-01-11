#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QVector"
//#include "tests.h"
#include"QDebug"

struct point{
    int x;
    int y;
    bool isFilled;
    QColor color;
};

class Board{
private:
    int cellsNumber=10;
    int cellSize=0;
    std::vector<point> points_list;
public:
    void createBoard(QGraphicsView *GraphicBoard);
    void undo();
    void open();
    void save();
    void exportToFile();
    void clear();
    void fillTable();
    void setCellsNumber(int cellsnumber);
    void setCellSize(int cellsize);
    std::vector<point> getPointList();
    int getCellSize();
    QColor getColorOfPoint(point point);
    int getCellsNumber();
    void setColor(QColor color, int index);
};
#endif // BOARD_H
