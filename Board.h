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
    int cellsnumber=10;
    int cell_size=0;
    std::vector<point> points_list;
public:
    void createBoard(QGraphicsView *GraphicBoard);
    void undo();
    void open();
    void save();
    void exportToFile();
    void clear();
    void fillTable();
    std::vector<point> getPointList();
    int getCellSize();
    QColor getColorOfPoint(point point);
    int getCellsNumber();
    void setColor(QColor color, int index);
};
#endif // BOARD_H
