#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tool.h"
#include "Brush.h"
#include "Eraser.h"
#include "ColorPalette.h"
#include "ColorPicker.h"
#include "Bucket.h"
#include "QGraphicsScene"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();

private slots:
    void on_btnBucket_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
//    Tool *tool= new Brush();
};
#endif // MAINWINDOW_H
