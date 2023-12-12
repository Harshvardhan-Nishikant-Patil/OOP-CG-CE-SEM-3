#include "mainwindow.h"
#include "./ui_mainwindow.h"

QImage img(400,400,QImage::Format_RGB888);

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

void MainWindow::DDA(float x1,float y1,float x2,float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float l;
    if(abs(dx)>abs(dy)){
        l=abs(dx);
    }
    else{
        l=abs(dy);
    }
    dx=dx/l;
    dy=dy/l;
    int i=0;
    while(i<=l){
        img.setPixel(x1,y1,qRgb(255,255,255));
        x1+=dx;
        y1+=dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow:: draw(int count, float x1, float y1, float x5, float y5){
    float x2,y2,x3,y3,x4,y4,dx,dy;
    if(count==1){
        DDA(x1,y1,x5,y5);
        return;
    }
    dx = (x5-x1)/3;
    dy = (y5-y1)/3;
    x2 = x1+dx;
    y2 = y1+dy;
    x4 = x1+2*dx;
    y4 = y1+2*dy;
    x3 = (x1+x5)/2+sqrt(3)*(y1-y5)/6;
    y3 = (y1+y5)/2+sqrt(3)*(x5-x1)/6;
    draw(count-1,x1,y1,x2,y2);
    draw(count-1,x2,y2,x3,y3);
    draw(count-1,x3,y3,x4,y4);
    draw(count-1,x4,y4,x5,y5);
}

void MainWindow::on_pushButton_clicked()
{
    int count;
    count = ui->textEdit->toPlainText().toInt();
    draw(count,100,100,200,200);
}

