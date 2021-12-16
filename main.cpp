
// Window Classes
#include "playwindow.h"
#include "startmenu.h"
#include "helpwindow.h"
#include "settingswindow.h"
#include "statswindow.h"

// Qt includes
#include "Qt_includes.h"



int main(int argc, char *argv[])
{


    QApplication qAppMain(argc, argv);

    qAppMain.setWindowIcon(QIcon(MAIN_APP_ICON_FILE));

    // start menu object
    StartMenu s;

    // Other windows
    PlayWindow pl;
    HelpWindow hlp;
    SettingsWindow stgWin;
    StatsWindow stWin;

    // userdata
    QSettings userData(ORGANISATION_NAME, APPLICATION_NAME);


    // linking other windows to start menu
    s.linkPlayWindow(&pl);
    s.linkHelpWindow(&hlp);
    s.linkSettingWindow(&stgWin);
    s.linkStatsWindow(&stWin) ;

    // link userData
    pl.linkUserData(&userData);
    stWin.linkUserData(&userData);
    s.linkUserData(&userData) ;


    s.checkUserData();
    //s.setRandomGameText();


    pl.linkParent(&s);
    stgWin.linkParent(&s);

    //pl.setBestScore();



    // Show main window
    s.show();



    /*

        // top 10 highest scores
        // record broken new entry in top 10

        // sentence through files

        // why explicit constructor is needed


    */

    /*
        Finally
        1. Icon - done
        2. Deploy via innosetup
        3. Help Rewrite
    */

    return qAppMain.exec();
}
