#ifndef TOOL_H
#define TOOL_H

#endif // TOOL_H
#include <QPointF>
class Tool {
public:
    Tool(){}
    virtual void use(QPointF point)=0;

};
