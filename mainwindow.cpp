#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(){
    board->createBoard(ui->GraphicBoard);
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

 qDebug() << "Mouse position in scene:" << scenePos;
}
