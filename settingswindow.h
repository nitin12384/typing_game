#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include "Qt_includes.h"
#include "startmenu.h"

class SettingsWindow : public QWidget
{
public:
    SettingsWindow();

    // Linking of parent
    // needed to call resetUserData function defined in parent
    void linkParent(StartMenu* win);

private:
    StartMenu* parentWin;

    void setUpUI();

    void resetData();

};

#endif // SETTINGSWINDOW_H
