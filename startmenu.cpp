#include "startmenu.h"

StartMenu::StartMenu()
{

    this->resize(MAIN_WIN_SIZEX, MAIN_WIN_SIZEY) ;
    this->setWindowTitle("Typing Pro");

    setUpUI();

    // it acess userdata
    // cant be called in constructor
    // setRandomGameText();

}

void StartMenu::linkPlayWindow(PlayWindow* win)
{
    this->playWindow = win;
}

void StartMenu::linkHelpWindow(QWidget *win)
{
    this->helpWindow = win;
}

void StartMenu::linkSettingWindow(QWidget *win)
{
    this->settingWindow = win;
}

void StartMenu::linkStatsWindow(StatsWindow *win)
{

    this->statsWindow = win;
}

void StartMenu::linkUserData(QSettings *usrData)
{
    this->usrData = usrData ;
}

void StartMenu::checkUserData()
{
    if( ! usrData->contains(BEST_SCORE_KEY)){
        resetUserData();
    }
}

// cannot be called before linking
void StartMenu::resetUserData()
{
    usrData->setValue(BEST_SCORE_KEY, 0) ;
    usrData->setValue(BEST_SPEED_KEY, 0.0f) ;

    usrData->setValue(AVG_SPEED_KEY, 0.0f) ;
    usrData->setValue(NUM_WORDS_KEY, 0) ;

    setRandomGameText();
}

void StartMenu::setRandomGameText()
{

    // print one of the four user stats
    int totStats = 4;
    srand(time(nullptr));
    int st = rand()%totStats + 1;

    if(TEST_MODE) st = 4;

    if(st == 1){
        // Best score
        int bestScore = usrData->value(BEST_SCORE_KEY).toInt();
        gameTextLbl->setText(QString("Your Best Score : ") + QString::number(bestScore)) ;
    }
    else if(st == 2){
        // Best Speed
        float bestSpeed = usrData->value(BEST_SPEED_KEY).toFloat();
        gameTextLbl->setText(QString("Your Best Speed(WPM) : ") + QString::number(bestSpeed, 'f', 2)) ;
    }
    else if(st == 3){
        // Avg. Speed
        float avgSpeed = usrData->value(AVG_SPEED_KEY).toFloat();
        gameTextLbl->setText(QString("Your Average Speed(WPM) : ") + QString::number(avgSpeed, 'f', 2)) ;
    }
    else if(st == 4){
        // word  typed
        int wordTyped = usrData->value(NUM_WORDS_KEY).toInt();
        gameTextLbl->setText(QString("Total Words Typed So Far : ") + QString::number(wordTyped)) ;
    }

}



void StartMenu::startPlay()
{
    this->hide();
    playWindow->setBestScoreLabel();
    playWindow->show();
}

void StartMenu::helpWin()
{
    helpWindow->show();
}

void StartMenu::settingsWin()
{
    settingWindow->show();
}

void StartMenu::statsWin()
{
    statsWindow->show();
    statsWindow->setFieldVals();
}

void StartMenu::setUpUI()
{
    // ----- Toolbar

    QPixmap help   (HELP_ICON_FILE) ;
    QPixmap settings(SETTINGS_ICON_FILE) ;

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QToolBar* tlb = this->addToolBar("Toolbar");
    tlb->setMovable(false);

    tlb->addSeparator();
    QAction* hlp = tlb->addAction( QIcon(help), "Help");
    tlb->addWidget(spacer);
    QAction* set = tlb->addAction( QIcon(settings), "Settings");
    tlb->addSeparator();


    connect(set, &QAction::triggered, this, &StartMenu::settingsWin);
    connect(hlp, &QAction::triggered, this, &StartMenu::helpWin);

    // ------ Central Widget

    playBtn = new QPushButton("Play");
    statsBtn = new QPushButton("Check your Stats");
    gameTextLbl = new QLabel("Typing for fun");

    // font of play button
    QFont playFont;
    // font size
    playFont.setPixelSize(80);
    playBtn->setFont(playFont);

    //styling ?? compilacted

    QWidget* mainWidget = new QWidget();
    QGridLayout* mainLayout = new QGridLayout(mainWidget);
    QWidget* spacer2 = new QWidget();
    QWidget* spacer3 = new QWidget();

    playBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    spacer3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // divided into grid of 12x12

    mainLayout->addWidget(spacer2,0,0,3,12);
    mainLayout->addWidget(playBtn, 3, 3, 3, 6);

    mainLayout->addWidget(gameTextLbl, 6, 0, 1, 12, Qt::AlignCenter);
    mainLayout->addWidget(statsBtn, 7, 3, 1, 6);

    mainLayout->addWidget(spacer3, 8,0,3,12);


    // add to the window
    this->setCentralWidget(mainWidget) ;

    // ---- Button connects

    connect(playBtn, &QPushButton::clicked, this, &StartMenu::startPlay) ;
    connect(statsBtn, &QPushButton::clicked, this, &StartMenu::statsWin) ;
}




