#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QVector"
#include "QWidget"
#include "QtWidgets"
//#include "tests.h"
#include"QDebug"
using namespace std;
#include <iostream>
#include <fstream>
struct point{
    int x;
    int y;
    QColor color;
};

class Board : public QGraphicsView{
private:
    int cellsNumber=10;
    int cellSize=0;
    std::vector<point> points_list;
    double previousScaleFactor = 1.0;
    QGraphicsScene *scene=nullptr;
public:
    Board(QWidget *parent = nullptr) : QGraphicsView(parent) {}
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

protected:
    void wheelEvent(QWheelEvent *event) override;
};
#endif // BOARD_H
