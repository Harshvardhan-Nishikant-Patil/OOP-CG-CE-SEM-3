#include "mainwindow.h"
#include "./ui_mainwindow.h"

QImage img(400,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bresenhmanCircle(200,200,100);
    bresenhmanCircle(200,200,50);
    DDA(200,100,200+86.66,250);
    DDA(200+86.66,250,200-86.66,250);
    DDA(200-86.66,250,200,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: plotpoint(float x, float y){
    img.setPixel(x,y,qRgb(255,255,255));
}

void MainWindow:: DDA(float x1, float y1, float x2, float y2){
    float dx = x2-x1;
    float dy = y2-y1;
    float step;
    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }
    float x = x1;
    float y = y1;
    dx = dx/step;
    dy = dy/step;
    for(int i=0;i<step;i++){
        plotpoint(x,y);
        x = x+dx;
        y = y+dy;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow:: bresenhmanCircle(float xc, float yc, float r){
    int x,y,d;
    x = 0;
    y = r;
    d = 3-2*r;
    while(x<=y){
        plotpoint(x+xc,y+yc);
        plotpoint(x+xc,-y+yc);
        plotpoint(-x+xc,y+yc);
        plotpoint(-x+xc,-y+yc);
        plotpoint(y+xc,x+yc);
        plotpoint(y+xc,-x+yc);
        plotpoint(-y+xc,x+yc);
        plotpoint(-y+xc,-x+yc);

        if(d<0){
            d = d+4*x+6;
            x = x+1;
        }
        else{
            d = d+4*(x-y)+10;
            x = x+1;
            y = y-1;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

