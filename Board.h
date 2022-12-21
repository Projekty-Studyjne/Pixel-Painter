#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QVector"

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
    QVector<point> points_list;
public:
    Board(){}
    void createBoard(QGraphicsView *GraphicBoard);
    void undo();
    void open();
    void save();
    void exportToFile();
    void clear();
    void fillTable();
    QVector<point> getPointList();
    int getCellSize();
    QColor getColorOfPoint(point point);
};
#endif // BOARD_H
