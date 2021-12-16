#include "playwindow.h"


PlayWindow::PlayWindow()
{
    setUpUI();
    setUpBtn();

    // game will start when user will press the start button
    started = false;

    lines = {
        "Do you worst",
        "Its never good",
        "good enough"
    };

    if(TEST_MODE==2){
        lines = {"asdf ;lkj asdf ;lkj"} ;
    }

//    lines = {
//        "upstairs status marie aft asphalt throat traces pvc",
//        "barnes talents sclerosis giants another bows organ",
//        "slr abstract lest listprice leaders livesex criteria",
//        "segments inquiries struts partitions gr saturated",
//        "artistic admissions rabbit jensen listings fifteen",
//        "novels cried sem transformation death collagen euros",
//        "salem clancy divers prescriptions datasets exclusive",
//        "enables dunes accelerate hero guitars horns farmer",
//        "installations sources trent msgid acting referrals",
//        "pauline bontril fh content bibliographic deficits",
//        "deutsche licensors pesticides mounting dose quoting",
//        "age minolta offline adverts blanca petit steadily",
//        "amg frankfurt wilde departments donate marine blowing",
//        "solitary dinners wireless dam trademarks withholding",
//        "indeed monica rank fee ahmad checkpoint delivery lift",
//        "beloved correlated authorisation requirement wildlife",
//        "roy taps approaching disk torres eager adjourned cid",
//        "saddam irs homosexual companion gamespot screenshots",
//        "lynch capsules cocaine triple told composer drink",
//        "orchid differing notch aruba layup pants evo kernels",
//        "extended kalamazoo month precipitation ncbi nightlife",
//        "nmr chair creep climax registry minor sailor prohibit",
//        "keeps epa sally antivirus khan marriages witnesses",
//        "exclude toward baker import boy logos hall mutations",
//        "poole traps tie criticized although cdr masterpiece",
//        "circuit italic entertaining reportedly silence hai",
//        "debra loading rubbish guideline propaganda cardio",
//        "foreclosure fleece eyewear nathan smugmug hotmail",
//        "francais datasheet valentines made kelly tracey incl",
//        "conclude perry graceful leslie celebrations producer",
//        "meters cultures regimen ll sampling disagree format",
//        "handling catalytic prevalent pakistan organization",
//        "shop rf tumor botswana regimen iowa vested strong",
//        "crow benefit audio retardation willard stan tucson",
//        "reject re certificates manipulated migraine cosmic",
//        "subscribed external tyranny muscles fetch lavigne",
//        "products je elapsed donna reagan europeans burner"
//     } ;

    //lines = {"asdf ;lkj asdf ;lkj asdf ;lkj asdf ;lkj"} ; // for testing purpose

}

PlayWindow::~PlayWindow()
{
    // dont need to destroy any thing, because of parent/ child heirarchy of QObjects
    // probably
}

void PlayWindow::linkParent(MyMainWindow *win)
{
    this->parentWin = win;
}

void PlayWindow::linkUserData(QSettings *usrData)
{
    this->usrData = usrData ;
}

void PlayWindow::setBestScoreLabel()
{
    int bestScore = 0;
    // Get best Score from userdata
    if(usrData != nullptr && usrData->contains(BEST_SCORE_KEY)){ // this check is mostly not needed
        bestScore = usrData->value(BEST_SCORE_KEY).toInt() ;
    }

    bestScoreLbl->setText("Best Score : "+QString::number(bestScore));
}

// overrided


void PlayWindow::setUpUI()
{
    this->setWindowTitle("Play");
    this->resize(MAIN_WIN_SIZEX, MAIN_WIN_SIZEY);

    QGridLayout* mainLayout = new QGridLayout(this);

    // Initialising UI elements
    QPixmap startPix    (START_ICON_FILE) ;
    QPixmap backPix     (BACK_ICON_FILE) ;

    QFont font1;
    // font size
    font1.setPixelSize(25);

    scoreLbl = new QLabel("Score : ");
    scoreValLbl = new QLabel("0");
    bestScoreLbl = new QLabel("Best Score :");

    textLbl = new QLabel("Text To Type");
    wonLbl = new QLabel("Press Start");
    startBtn = new QPushButton(QIcon(startPix) , " Start");
    backBtn = new QPushButton(QIcon(backPix), " Back");

    textLbl->setFont(font1);
    wonLbl->setFont(font1);
    scoreLbl->setFont(font1);
    bestScoreLbl->setFont(font1);
    scoreValLbl->setFont(font1);
    //startBtn->setFont(font1);
    //backBtn->setFont(font1);


    // this prevents automatic clicking on the buttons on pressing spacebar
    startBtn->setFocusPolicy(Qt::NoFocus);
    backBtn->setFocusPolicy(Qt::NoFocus);

    // To occupy rows in Layout
    QLabel* spacer = new QLabel();


    // ---------  Arranging the UI

    // divide window in 12 rows
    // divide all rows in 12 columns

    mainLayout->addWidget(bestScoreLbl, 4, 0, Qt::AlignLeft) ;
    mainLayout->addWidget(scoreLbl, 4, 10, Qt::AlignRight);

    //scoreValLbl->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

    mainLayout->addWidget(scoreValLbl, 4, 11);

    mainLayout->addWidget(textLbl, 5, 0, 1, 12, Qt::AlignCenter);

    mainLayout->addWidget(startBtn, 7, 2, 1, 2);
    mainLayout->addWidget(backBtn, 7, 6, 1, 2);

    mainLayout->addWidget(wonLbl, 8, 0, 1, 12, Qt::AlignCenter);

    mainLayout->addWidget(spacer, 11, 0);

    //startBtn->adjustSize();

    mainLayout->setVerticalSpacing(10);





}

void PlayWindow::setUpBtn()
{
    this->connect(startBtn, &QPushButton::clicked, this, &PlayWindow::startGame);
    this->connect(backBtn, &QPushButton::clicked, this, &PlayWindow::endGame);
}

void PlayWindow::setRandText()
{
    curText = generator.sentenceRandom();

    if(TEST_MODE){
        int n = lines.size();
        srand(timer.elapsed()) ;
        int k = rand() % n ;
        curText = lines[k] ;
    }
}

void PlayWindow::startGame()
{
    // this function is ran when user clicks start button

    // set a new random text for user to type
    setRandText();

    // Reset current typing specific variable and counters
    started=true;
    score=0;
    curTextPos=0;
    lastPos = curText.size();

    // measuring speed in WPM
    // start pressed time
    startTime.start();
    // number of words
    nWords = 1;

    // to measure accuracy
    totPress = 0;
    correctPress = 0;


    // timer for scoring
    timer.start();

    updateGameUIData(false); // pressedWrong = false

    wonLbl->setText("");
}

void PlayWindow::keyPressEvent(QKeyEvent *evt)
{
    if(started){

        // if shift or other thigs are pressed, then dont check further
        if(evt->text() == ""){
            return;
        }

        QChar pressed = evt->text().at(0) ;
//        bool pressedWrong = checkPressedKey(pressed);
//        updateTextLabelAccProgress(pressedWrong);
//        updateGameUIData();
//        checkFinished();




        bool pressedWrong = ! checkPressedKey(pressed);

        updateGameData(pressedWrong, pressed);
        updateGameUIData(pressedWrong);
        checkFinished();
    }
}

void PlayWindow::updateGameData(bool pressedWrong, const QChar& pressedKey)
{
    float diff = timer.elapsed();

    timer.start();

    totPress ++ ;

    if( ! pressedWrong ){
        curTextPos++;
        correctPress++;

        // expected time = AVG_EXP_PRESS_TIME
        // taken time = diff
        score += AVG_CORRECT_SCORE*(AVG_EXP_PRESS_TIME/diff);

        // words count
        if(pressedKey == ' '){
            nWords ++;
        }
    }
    else{
        // penalty for wrong key

        score -= WRONG_PENALTY ;

        if(score < 0){
            score = 0;
        }
    }
}

// return true if key pressed correct
bool PlayWindow::checkPressedKey(const QChar &key)
{
    return key==curText.at(curTextPos) ;
    /*
    float diff = timer.elapsed();
    //float diff =QTime::currentTime().msec() - lastPressTime.msec();

    // update
    // lastPressTime = QTime::currentTime();
    timer.start();

    if( key==curText.at(curTextPos) ){
        curTextPos++;

        // expected time = 100 msec
        // taken time = diff

        score += 10*(100.0/diff);

        // words
        if(key == ' '){
            nWords ++;
        }

        return true;
    }
    else{
        // penalty for wrong key

        score -= 2 ;

        if(score < 0){
            score = 0;
        }
        return false;
    }
    */

}

void PlayWindow::updateGameUIData(bool pressedWrong)
{
    // update textLabel
    updateTextLabelAccProgress(pressedWrong);

    // update score
    scoreValLbl->setText(QString::number(score));
}

void PlayWindow::checkFinished()
{
    if(curTextPos == lastPos){

        // get speed
        float wpm = 0.0f;
        wpm = nWords / (startTime.elapsed()/60000.0) ;

        // get accuracy
        float accur = 0.0f;
        accur = (100.0*correctPress)/totPress ;

        wonLbl->setText(QString(WON_TEXT) + QString(" Speed in Wpm : ") + QString::number(wpm, 'f', 2)
                        + QString(" Accuracy :") + QString::number(accur, 'f', 2) + QString("%")
                        );

        // dont reset score, nWords by now
        updateUserDataOnFinish(wpm);

        started = false;
    }
}

void PlayWindow::updateUserDataOnFinish(float curSpeed)
{
    // all fields in usrData should be set by now
    // ????????????????????????????

    // best score
    int curBestScore = usrData->value(BEST_SCORE_KEY).toInt();
    if(score > curBestScore){
        curBestScore = score ;
    }
    usrData->setValue(BEST_SCORE_KEY, curBestScore) ;

    // best speed
    float curBestSpeed = usrData->value(BEST_SPEED_KEY).toFloat();
    if(curSpeed > curBestSpeed){
        curBestSpeed = curSpeed ;
    }
    usrData->setValue(BEST_SPEED_KEY, curBestSpeed) ;

    // avg speed and numwords
    int words_so_far = usrData->value(NUM_WORDS_KEY).toInt();
    float avgSpeed = usrData->value(AVG_SPEED_KEY).toFloat();

    // intially avgSpeed = 0.0

    float zero = 1e-3 ;

    float timeSoFar = 0.0;



    if(avgSpeed > zero){
        timeSoFar += words_so_far/avgSpeed ;
    }

    if(curSpeed > zero){
        timeSoFar += nWords/curSpeed;
    }
    words_so_far += nWords ;

    if(timeSoFar > zero){
        avgSpeed = words_so_far / timeSoFar ;
    }
    else{
        avgSpeed = curSpeed ;
    }


    usrData->setValue(AVG_SPEED_KEY, avgSpeed) ;
    usrData->setValue(NUM_WORDS_KEY, words_so_far) ;

    setBestScoreLabel();
}

void PlayWindow::setTextLabel(const QString &green, const QString &red, const QString &grey, const QString &black)
{
    // set lbl using html
    static QString stGreen = "<font color=green>" ;
    static QString stRed = "<font color=red>" ;
    static QString stGrey = "<font color=grey>" ;
    static QString stBlack = "<font color=black>" ;
    static QString endHTML = "</font>" ;

    textLbl->setText(stGreen + green + endHTML +
                     stRed + red + endHTML +
                     stGrey + grey + endHTML +
                     stBlack + black + endHTML) ;

}

void PlayWindow::updateTextLabelAccProgress(bool pressedWrong)
{
    // [0 to curTextPos] is green - has been typed
    // no. of char in green = curTextPos

    // curTextPos may be grey or red
    // starts at curTextPos, length = 1

    // rest is black
    // starts at curTextPos + 1
    // ends at lastPos
    // no. of char = lastPos-curTextPos

    static QString green;
    static QString red;
    static QString grey;
    static QString black;

    green = curText.left(curTextPos);

    red = "";
    grey = curText.mid(curTextPos, 1) ;
    if(pressedWrong){
        red = grey ;
        grey = "";
    }

    black = curText.right(lastPos - curTextPos - 1);
    if(curTextPos == lastPos) black = "";

    setTextLabel(green, red, grey, black);


}

void PlayWindow::endGame()
{
    parentWin->show();
    parentWin->setFocus();

    this->hide();
}

