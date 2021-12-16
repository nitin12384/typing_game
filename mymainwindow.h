#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

class MyMainWindow : public QMainWindow
{
public:
    MyMainWindow(){

    }

    virtual void withShow(){

    }

    // override
    void show(){
        QMainWindow::show();
        withShow();
    }



};

#endif // MYMAINWINDOW_H
