#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QWidget>
#include "Qt_includes.h"

class StatsWindow : public QWidget
{
public:
    StatsWindow();

    // linking QSetting object containing user data
    void linkUserData(QSettings* usrData);

    // cant be called untill usrdata is initialised in start menu
    // should be called every time show() is called
    void setFieldVals();

private:

    void setUpUI();



    // userData
    QSettings* usrData;

    // UI variable
    QLabel* bestScoreValLbl;
    QLabel* bestSpeedValLbl;
    QLabel* avgSpeedValLbl;
    QLabel* wordTypedValLbl;




};

#endif // STATSWINDOW_H
