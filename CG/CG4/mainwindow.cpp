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

void MainWindow::DDA(float x1, float y1, float x2, float y2)
{
    float x, y;
    float dx, dy, x_inc, y_inc, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }else{
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
}

void MainWindow::on_pushButton_clicked()
{
    DDA(0,200,400,200);
    DDA(200,0,200,400);
    int Ox, Oy, l;
    Ox = ui->textEdit_6->toPlainText().toInt();
    Oy = ui->textEdit_7->toPlainText().toInt();
    l = ui->textEdit_8->toPlainText().toInt();
    double x=Ox+l/2;
    double y=Oy+(1.7321)*(l/2);
    DDA(200+Ox,200-Oy,200+Ox+l,200-Oy);
    DDA(200+Ox,200-Oy,200+x,200-y);
    DDA(200+x,200-y,200+Ox+l,200-Oy);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    int Ox, Oy, l,tx,ty;
    tx = ui->textEdit->toPlainText().toInt();
    ty = ui->textEdit_2->toPlainText().toInt();
    Ox = ui->textEdit_6->toPlainText().toInt();
    Oy = ui->textEdit_7->toPlainText().toInt();
    l = ui->textEdit_8->toPlainText().toInt();
    double x=Ox+l/2;
    double y=Oy+(1.7321)*(l/2);
    DDA(200+Ox+tx,200-Oy-ty,200+Ox+l+tx,200-Oy-ty);
    DDA(200+Ox+tx,200-Oy-ty,200+x+tx,200-y-ty);
    DDA(200+x+tx,200-y-ty,200+Ox+tx+l,200-Oy-ty);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    int Ox, Oy, l;
    float Sx,Sy;
    Sx = ui->textEdit_3->toPlainText().toInt();
    Sy = ui->textEdit_4->toPlainText().toInt();
    Ox = ui->textEdit_6->toPlainText().toInt();
    Oy = ui->textEdit_7->toPlainText().toInt();
    l = ui->textEdit_8->toPlainText().toInt();
    double x=Ox+l/2;
    double y=Oy+(1.7321)*(l/2);
    DDA(200+Sx*(Ox),200-Sy*(Oy),200+Sx*(Ox+l),200-Sy*(Oy));
    DDA(200+Sx*(Ox),200-Sy*(Oy),200+Sx*(x),200-Sy*(y));
    DDA(200+Sx*(x),200-Sy*(y),200+Sx*(Ox+l),200-Sy*(Oy));
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked()
{
    int Ox, Oy, l;
    double θ;
    θ = ui->textEdit_5->toPlainText().toInt();
    Ox = ui->textEdit_6->toPlainText().toInt();
    Oy = ui->textEdit_7->toPlainText().toInt();
    l = ui->textEdit_8->toPlainText().toInt();
    θ=θ*0.017453;
    double x3=(Ox+l/2)*cos(θ)-(Oy+(1.7321)*(l/2))*sin(θ);
    double y3=(Ox+l/2)*sin(θ)+(Oy+(1.7321)*(l/2))*cos(θ);
    double x1=(Ox)*cos(θ)-(Oy)*sin(θ);
    double y1=(Ox)*sin(θ)+(Oy)*cos(θ);
    double x2=(Ox+l)*cos(θ)-(Oy)*sin(θ);
    double y2=(Ox+l)*sin(θ)+(Oy)*cos(θ);
    DDA(200+x1,200-y1,200+x2,200-y2);
    DDA(200+x1,200-y1,200+x3,200-y3);
    DDA(200+x2,200-y2,200+x3,200-y3);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
