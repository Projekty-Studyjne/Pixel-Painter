#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene(ui->GraphicBoard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(){

}


void MainWindow::on_btnBucket_clicked()
{

}

