#ifndef TOOL_H
#define TOOL_H

#endif // TOOL_H
#include <QPointF>
#include "Board.h"
using namespace std;
class Tool {
public:
    Tool(){}
    virtual void use(vector<point> list, QPointF point)=0;
};
