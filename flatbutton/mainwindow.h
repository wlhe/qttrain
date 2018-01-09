#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class FlatButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void btton2Clicked();

private:
    Ui::MainWindow *ui;

    FlatButton *button1;
    FlatButton *button2;
    bool checked;
};

#endif // MAINWINDOW_H
