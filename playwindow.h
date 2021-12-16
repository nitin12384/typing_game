#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include "Qt_includes.h"
#include "sentencegenrator.h"
#include "mymainwindow.h"

#include <QWidget>

class PlayWindow : public QWidget
{

public:
    PlayWindow();
    ~PlayWindow();

    // Linking of parent window to facilitate switching windows
    // needs to be called in main.cpp
    // could also use a constructor for that
    void linkParent(MyMainWindow* win);

    // linking QSetting object containing user data
    void linkUserData(QSettings* usrData);

    // set best score, shall called only after linkingof user data
    void setBestScoreLabel();

    // override show() to call setBestScore() after the linking and after the constructor
    // void show();

private:

    // Basic setting up
    void setUpUI();
    void setUpBtn();



    // Start the game
    void startGame();

    // Set the current text to a random text
    void setRandText();

    // Overriding default handler of QWidget
    void keyPressEvent(QKeyEvent* evt);
    //void keyReleaseEvent(QKeyEvent* evt);

    // update Score and Game Data according to key pressed
    void updateGameData(bool pressedWrong, const QChar& pressedKey);

    // update Score Label and current text label according to progress
    void updateGameUIData(bool pressedWrong);

    // return true if current expected key is pressed
    bool checkPressedKey(const QChar& key);

    // Check if text to be typed is over on each correct keypress event
    void checkFinished();

    // Update : max speed, max score, total word typed so far, avg speed
    // nWords, score are class variables
    void updateUserDataOnFinish(float curSpeed);

    // set the type label acc to given colours
    void setTextLabel(const QString& green, const QString& red, const QString& grey, const QString& black);

    // Decides coulour of the portions of the text ans then update text
    // according to current progress
    void updateTextLabelAccProgress(bool pressedWrong);

    // Stop game, switch back to start menu
    // Check if parent win is null
    // then quit the application
    void endGame();


    // ------------- Variables

    // For switching back to start menu
    MyMainWindow* parentWin;

    // userData
    QSettings* usrData; // userData is already a function of QObject class

    // To generate random sentence from a file
    SentenceGenrator generator;

    // UI Variable
    QLabel* scoreLbl;
    QLabel* scoreValLbl;
    QLabel* bestScoreLbl;

    QLabel* textLbl;
    QLabel* wonLbl;
    QPushButton* startBtn;
    QPushButton* backBtn;


    // State Variables

    // for testing purpose
    std::vector<QString> lines;

    // current text which is being typed
    QString curText;

    // pos of last char in whole curText
    int lastPos;

    // pos of cur Expected Char in cutText
    int curTextPos;

    int score;

    // Game started or not
    bool started;

    int nWords;

    // to measure accuracy
    int totPress;
    int correctPress;

    // To measure final WPM speed
    QTime startTime;
    QTime timer;


};
#endif // PLAYWINDOW_H
