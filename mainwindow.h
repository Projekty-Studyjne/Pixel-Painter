#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Brush.h"
#include <QMouseEvent>
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
    void on_btnBrush_clicked();
private:
    Ui::MainWindow *ui;
    Board *board;
    Tool *tool= new Brush();
protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
