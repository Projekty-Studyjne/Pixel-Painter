#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
   tool->use(board->getPointList(),scenePos);
 qDebug() << "Mouse position in scene:" << scenePos;
}
