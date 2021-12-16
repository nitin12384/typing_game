#ifndef SENTENCEGENRATOR_H
#define SENTENCEGENRATOR_H


#include "Qt_includes.h"

class SentenceGenrator
{
public:
    SentenceGenrator();
    ~SentenceGenrator();

    QString sentenceByIndex(int index=0, int file=0);
    QString sentenceRandom(int seed=0);

    void setWordLimit(int minChar, int maxChar);
    void setTotalCharLimit(int minTotChar, int maxTotChar) ;

    void setDataFile(std::string fname);

private:
    void resetDefaults();

    void openFile();

    QTime timerRand;

    int minWordChar;
    int maxWordChar;
    int minTotChar;
    int maxTotChar;

    int totalCharInFile;

    int nLines;

    std::string sentenceFileName;
    std::ifstream sentenceFile;


};

#endif // SENTENCEGENRATOR_H
