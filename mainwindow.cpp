#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"
#include <QPoint>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(int i = 0; i<points.size(); i++){
        points[i]->draw(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *p = nullptr;
    bool not_create = false;

    QPoint checkpoint;
    checkpoint.setX(event->x());
    checkpoint.setY(event->y());

    for(int i = 0; i < points.size(); i++){
        if(points[i]->distance2(checkpoint) <= 5){
            delete points[i];
            points.remove(i);
            not_create = true;
        }
     }
    if(!not_create){
        p = new Point(event->x(), event->y());
        if(p)
            points.append(p);
    }
    repaint();
}
