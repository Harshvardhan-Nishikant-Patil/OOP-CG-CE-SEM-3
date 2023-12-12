#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void plotpoint(float x,float y);
    void DDA(float x1,float y1,float x2,float y2);
    void bresenhmanCircle(float xc,float yc,float r);
};
#endif // MAINWINDOW_H
