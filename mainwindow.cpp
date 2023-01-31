#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Dodanie layoutu zeby moc dodawac nowe widgety w kodzie
    ui->centralwidget->setLayout(new QVBoxLayout);
    ui->centralwidget->layout()->addWidget(colorPalette);
    colorPalette->setOptions(
                    ColorPalette::DontUseNativeDialog
                    | ColorPalette::NoButtons);

    board->createBoard(ui->GraphicBoard);
    board->fillTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrush_clicked()
{
    tool = new Brush();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   QPoint globalPos = QCursor::pos();
   QPoint viewPos = ui->GraphicBoard->mapFromGlobal(globalPos);
   QPointF scenePos = ui->GraphicBoard->mapToScene(viewPos);
   tool->use(*board,scenePos,*colorPalette);
//        for(int i=0;i<board->getPointList().size();i++){
//            qInfo()<<"x: " << board->getPointList()[i].x << "y: " << board->getPointList()[i].y << "color: " << board->getPointList()[i].color.toRgb();
//        }
   board->createBoard(ui->GraphicBoard);
}

void MainWindow::on_sldCellsNumber_valueChanged(int value)
{
    board->setCellsNumber(value);
    board->createBoard(ui->GraphicBoard);
}

void MainWindow::on_btnEraser_clicked()
{
    delete tool;
    tool = new Eraser();
}


void MainWindow::on_btnBucked_clicked()
{
    delete tool;
    tool = new Bucket();
}

