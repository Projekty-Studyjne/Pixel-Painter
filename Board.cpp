#include <Board.h>

void Board::fillTable(){
    points_list.clear();
    point new_point;
    for(int x=0;x<cellsNumber;x++){
        for( int y=0;y<cellsNumber;y++){
            new_point={x,y,Qt::white};
            this->points_list.push_back(new_point);
            }
    }
}

void Board::resizeTable(int new_size){
    std::vector<point> temp_point_list;
    for(int i=0;i<points_list.size();i++){
        temp_point_list.push_back(points_list[i]);
    }
    points_list.clear();
    fillTable();
    if((new_size*new_size)>temp_point_list.size()){
    for(int i=0;i<temp_point_list.size();i++){
        if(temp_point_list[i].isFilled){
            point point;
            point.x=temp_point_list[i].x;
            point.y=temp_point_list[i].y;
            int index=getIndexOfPoint(point);
            points_list[index].color=temp_point_list[i].color;
            points_list[index].isFilled=temp_point_list[i].isFilled;
        }
    }
    }
    else{
        for(int i=0;i<points_list.size();i++){
            point point;
            point.x=temp_point_list[i].x;
            point.y=temp_point_list[i].y;
            if(point.x<cellsNumber && point.y<cellsNumber){
            int index=getIndexOfPoint(point);
            points_list[index].color=temp_point_list[i].color;
            points_list[index].isFilled=temp_point_list[i].isFilled;
            }
        }
    }
}

void Board::createBoard(QGraphicsView *GraphicBoard){
    double scale = GraphicBoard->transform().m11();
    QPointF previousCenter = GraphicBoard->mapToScene(GraphicBoard->viewport()->rect().center());
    scene = new QGraphicsScene();
    GraphicBoard->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush;
    int window_size=600;
    cellSize=window_size/cellsNumber;
    setCellSize(cellSize);
    for(int wielkosc_x=0; wielkosc_x<cellsNumber; wielkosc_x++){
        for(int wielkosc_y=0; wielkosc_y<cellsNumber; wielkosc_y++){
          QColor color(getColorOfPoint({wielkosc_x, wielkosc_y}));
         scene->addRect(wielkosc_x*cellSize, wielkosc_y*cellSize, cellSize, cellSize, blackpen, color);
        }
    }
    GraphicBoard->resetTransform();
    GraphicBoard->scale(scale, scale);
    GraphicBoard->centerOn(previousCenter);
}

int Board::getCellSize(){
    return cellSize;
}

int Board::getCellsNumber(){
    return cellsNumber;
}

std::vector<point> Board::getPointList(){
    return points_list;
}

QColor Board::getColorOfPoint(point point){
        QColor color=Qt::white;
        for(int index=0; index<points_list.size(); index++){
            if(point.x==points_list[index].x && point.y==points_list[index].y){
                color=points_list[index].color;
                }
            }
        return color;
}

int Board::getIndexOfPoint(point point){
    int point_index;
    for(int index=0; index<points_list.size(); index++){
        if(point.x==points_list[index].x && point.y==points_list[index].y){
            point_index=index;
            }
        }
    return point_index;
}

void Board::setColor(QColor color, int index){
    points_list[index].color = color;
}




void Board::setFilled(bool isFilled,int index){
    points_list[index].isFilled=isFilled;
}

void Board::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.15;
    if(event->angleDelta().y()>0){
        scale(scaleFactor,scaleFactor);
//        previousScaleFactor = scaleFactor;
    }
    else{
        scale(1/scaleFactor, 1/scaleFactor);
//        previousScaleFactor = scaleFactor;
    }
}

void Board::setCellsNumber(int cellsnumber){
    this->cellsNumber=cellsnumber;
    resizeTable(cellsNumber);
    //fillTable();

}

void Board::setCellSize(int cellsize){
    this->cellSize=cellSize;
}

void Board::exportToFile(){
    if(scene!=nullptr){
        QPen blackpen(Qt::white);
        for(int wielkosc_x=0; wielkosc_x<cellsNumber; wielkosc_x++){
            for(int wielkosc_y=0; wielkosc_y<cellsNumber; wielkosc_y++){
                QColor color(getColorOfPoint({wielkosc_x, wielkosc_y}));
                scene->addRect(wielkosc_x*cellSize, wielkosc_y*cellSize, cellSize, cellSize, QPen(Qt::transparent), color);
            }
        }
        QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter painter(&image);
        scene->render(&painter);
        QPen blackpen1(Qt::darkGray);
        for(int wielkosc_x=0; wielkosc_x<cellsNumber; wielkosc_x++){
            for(int wielkosc_y=0; wielkosc_y<cellsNumber; wielkosc_y++){
                QColor color(getColorOfPoint({wielkosc_x, wielkosc_y}));
                scene->addRect(wielkosc_x*cellSize, wielkosc_y*cellSize, cellSize, cellSize, blackpen1, color);
            }
        }
        QString fileName = QFileDialog::getSaveFileName(0, "Save Image", "", "*.jpg;;*.png");
        if(!fileName.isEmpty()) {
            image.save(fileName);
        }
    }
}

void Board::save(){
    QString fileName = QFileDialog::getSaveFileName(0, "Save File", "", "*.txt");
    if(!fileName.isEmpty()){
        ofstream file(fileName.toStdString());
        for(int i=0; i<points_list.size(); i++){
            file <<points_list[i].x <<" ";
            file <<points_list[i].y <<" ";
            file <<points_list[i].color.red() << " ";
            file <<points_list[i].color.green() << " ";
            file <<points_list[i].color.blue() << endl;
            }
        file.close();
        }
}
void Board::open(){
    QString fileName = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
    if(!fileName.isEmpty()){
        points_list.clear();
        int x,y,r,g,b;
        std::ifstream file(fileName.toStdString());
        for(int i=0;!file.eof();i++){
            file>>x, file>>y, file>>r, file>>g, file>>b ;
            points_list.push_back({x,y,{r,g,b}});
        }
        file.close();
    }
}


