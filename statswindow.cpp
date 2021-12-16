#include "statswindow.h"

StatsWindow::StatsWindow()
{
    this->setWindowTitle("Stats") ;
    this->resize(OTHER_WIN_SIZEX, OTHER_WIN_SIZEY) ;

    setUpUI();
}

void StatsWindow::linkUserData(QSettings *usrData)
{
    this->usrData = usrData ;
}

void StatsWindow::setFieldVals()
{
    // Best score
    int bestScore = usrData->value(BEST_SCORE_KEY).toInt();
    bestScoreValLbl->setText(QString::number(bestScore)) ;


    // Best Speed
    float bestSpeed = usrData->value(BEST_SPEED_KEY).toFloat();
    bestSpeedValLbl->setText(QString::number(bestSpeed, 'f', 2)) ;


    // Avg. Speed
    float avgSpeed = usrData->value(AVG_SPEED_KEY).toFloat();
    avgSpeedValLbl->setText(QString::number(avgSpeed, 'f', 2)) ;

    // word  typed
    int wordTyped = usrData->value(NUM_WORDS_KEY).toInt();
    wordTypedValLbl->setText(QString::number(wordTyped)) ;

}


void StatsWindow::setUpUI()
{
    // use form layout
    QFormLayout* mainLayout = new QFormLayout(this);

    QLabel* bestScoreLbl = new QLabel("Your Best Score : ");
    QLabel* bestSpeedLbl = new QLabel("Your Best Speed(WPM) : ");
    QLabel* avgSpeedLbl = new QLabel("Your Average Speed(WPM) : ");
    QLabel* wordTypedLbl = new QLabel("Total Words Typed So Far : ");

    bestScoreValLbl = new QLabel("");
    bestSpeedValLbl = new QLabel("");
    avgSpeedValLbl = new QLabel("");
    wordTypedValLbl = new QLabel("");

    //setFieldVals();

    mainLayout->addRow(bestScoreLbl, bestScoreValLbl);
    mainLayout->addRow(bestSpeedLbl, bestSpeedValLbl);
    mainLayout->addRow(avgSpeedLbl, avgSpeedValLbl);
    mainLayout->addRow(wordTypedLbl, wordTypedValLbl);

}

