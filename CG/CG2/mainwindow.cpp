#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>
#include <QMouseEvent>

QImage img(400,400,QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(float x1,float y1,float x2, float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float length;
    if(abs(dx)<abs(dy)){
        length=abs(dy);
    }
    else{
        length=abs(dx);
    }
    float x=x1;
    float y=y1;
    dx=dx/length;
    dy=dy/length;
    for(int i=0;i<=length;i++){
        img.setPixel(x,y,color.rgb());
        x=x+dx;
        y=y+dy;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor();
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(start){
        float x = event->pos().x();
        float y = event->pos().y();
        a[count] = x;
        b[count] = y;
        if(event->button() == Qt::RightButton){
            DDA(a[0],b[0],a[count-1],b[count-1]);
            start = false;
        }
        else{
            if(count>0){
                DDA(a[count-1],b[count-1],a[count],b[count]);
            }
            count++;
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    a[count] = a[0];
    b[count] = b[0];
    float x[count];
    double m[count];
    for(int j=0;j<count;j++){
        int dx = a[j+1]-a[j];
        int dy = b[j+1]-b[j];
        if(dy == 0){
            m[j] = 1.0;
        }
        else if(dx == 0){
            m[j] = 0;
        }
        else{
            m[j] = double (dx)/dy;
        }
    }
    for(int i=0;i<=400;i++){
        int k=0;
        for(int j=0;j<count;j++){
            if(b[j]>i && b[j+1]<=i || b[j+1]>i && b[j]<=i){
                x[k] = a[j] + m[j]*(i-b[j]);
                k++;
            }
        }
        for(int j=0;j<k;j+=2){
            DDA(x[j],i,x[j+1],i);
        }
    }
}

