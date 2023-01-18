#pragma once
#ifndef TOOL_H
#define TOOL_H

#endif // TOOL_H
#include <QPointF>
#include "Board.h"
using namespace std;
class Tool {
public:
    Tool(){}
    virtual void use(Board &board, QPointF point)=0;
};
