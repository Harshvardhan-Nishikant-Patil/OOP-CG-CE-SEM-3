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

void MainWindow::DDA(float x1, float y1, float x2, float y2){

    float x, y;
    float dx, dy, x_inc, y_inc, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }
    x_inc = dx / steps;
    y_inc = dy / steps;
    x = x1;
    y = y1;
    int i = 0;
    while(i<=steps){
        img.setPixel(x, y, qRgb(255,255,255));
        x = x + x_inc;
        y = y + y_inc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::regioncode(float x,float y){
    int code = 0;
    if(x<50){
        code |= 8;
    }
    if(x>350){
        code |= 4;
    }
    if(y<50){
        code |= 2;
    }
    if(y>350){
        code |= 1;
    }
    return code;
}

void MainWindow::on_pushButton_clicked()
{
    DDA(50,50,350,50);
    DDA(350,50,350,350);
    DDA(50,350,350,350);
    DDA(50,50,50,350);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    int code1=regioncode(x1,y1);
    int code2=regioncode(x2,y2);
    DDA(x1,y1,x2,y2);
    float m=float(y2-y1)/float(x2-x1);
    while(true){
        if(code1==0 && code2==0){
            DDA(x1,y1,x2,y2);
            break;
        }
        if(code1 & code2 !=0){
            break;
        }
        else{
            int x,y,curr;
            if(code1==0){
                curr=code2;
            }
            else{
                curr=code1;
            }
            if(curr&8){
                y=y1+m*(50-x1);
                x=50;
            }
            else if(curr&4){
                y=y1+m*(350-x1);
                x=350;
            }
            else if(curr&2){
                x=x1+(50-y1)/m;
                y=50;
            }
            else if(curr&1){
                x=x1+(350-y1)/m;
                y=350;
            }
            if(curr=code1){
                x1=x;
                y1=y;
                code1=regioncode(x1,y1);
            }
            else{
                x2=x;y2=y;
                code2=regioncode(x2,y2);
            }
        }
    }
    DDA(50,50,50,350);
    DDA(50,50,350,50);
    DDA(350,350,50,350);
    DDA(350,350,350,50);
}


void MainWindow::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    DDA(x1,y1,x2,y2);
}

