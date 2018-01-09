#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "flatbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    checked(false)
{
    ui->setupUi(this);
    button1 = new FlatButton(QString("test"), this);
    button1->setGeometry(QRect(60, 80, 60, 30));
    button1->setObjectName(QString("button1"));

    QPixmap p(":/images/qt_extended_32x32.png");
    button2 = new FlatButton(p, this);
    button2->setGeometry(QRect(60, 120, 32, 32));
    connect(button2, &FlatButton::clicked, this, &MainWindow::btton2Clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete button1;
    delete button2;
}

void MainWindow::btton2Clicked()
{
    QPixmap p1(":/images/qt_extended_32x32.png");
    QPixmap p2(":/images/qt_extended_48x48.png");
    if(checked) {
        button2->setPixmap(p1);
    } else {
        button2->setPixmap(p2);
    }
    checked = !checked;
    button2->update();
}
