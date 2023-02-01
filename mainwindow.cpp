#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnBrush->setIcon(QIcon(":/icons/brush.png"));
    ui->btnBrush->setIconSize(QSize(60, 60));

    ui->btnEraser->setIcon(QIcon(":/icons/eraser.png"));
    ui->btnEraser->setIconSize(QSize(60, 60));

    ui->btnBucked->setIcon(QIcon(":/icons/bucket.png"));
    ui->btnBucked->setIconSize(QSize(60, 60));

    ui->btnClear->setIcon(QIcon(":/icons/clear.png"));
    ui->btnClear->setIconSize(QSize(60, 60));

    //Dodanie layoutu zeby moc dodawac nowe widgety w kodzie
    ui->centralwidget->setLayout(new QVBoxLayout);
    ui->centralwidget->layout()->addWidget(colorPalette);
    colorPalette->setOptions(
                    ColorPalette::DontUseNativeDialog
                    |ColorPalette::NoButtons);
colorPalette->setStyleSheet("QPushButton{ color: white}");
    board->createBoard(ui->GraphicBoard);
    board->fillTable();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrush_clicked()
{
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: white}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: white}");
    delete tool;
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
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: white}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: white}");
    delete tool;
    tool = new Eraser();
}


void MainWindow::on_btnBucked_clicked()
{
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: white}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: white}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    delete tool;
    tool = new Bucket();
}

void MainWindow::on_btnClear_clicked()
{
   board->fillTable();
   board->createBoard(ui->GraphicBoard);
}



