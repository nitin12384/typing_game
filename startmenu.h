#ifndef STARTMENU_H
#define STARTMENU_H

#include "mymainwindow.h"
#include "Qt_includes.h"

#include "playwindow.h"
#include "statswindow.h"

class StartMenu : public MyMainWindow
{
public:
    StartMenu();

    void linkPlayWindow(PlayWindow* win);
    void linkHelpWindow(QWidget* win);
    void linkSettingWindow(QWidget* win);
    void linkStatsWindow(StatsWindow* win);

    // linking QSetting object containing user data
    void linkUserData(QSettings* usrData);

    // must be called
    // Checks if userData exist or not, otherwize resets it(which leads to first time creation of userData)
    void checkUserData();

    // UserDataReset
    // cannot be called before linking
    void resetUserData();

    // can only be called after linking the userData
    void setRandomGameText();

    //override
    void withShow(){
        setRandomGameText();
    }



private:
    // navigation functions
    void startPlay();
    void helpWin();
    void settingsWin();
    void statsWin();

    void setUpUI();





    // userData
    QSettings* usrData; // userData is already a function of QObject class

    PlayWindow* playWindow;
    QWidget* helpWindow;
    QWidget* settingWindow;
    StatsWindow* statsWindow;

    // UI elements
    QPushButton* playBtn;
    QPushButton* statsBtn;
    QLabel* gameTextLbl;

};

#endif // STARTMENU_H
