#include "sentencegenrator.h"

SentenceGenrator::SentenceGenrator()
{
    resetDefaults();
    openFile();
    timerRand.start();
}

SentenceGenrator::~SentenceGenrator()
{
    sentenceFile.close();
}

QString SentenceGenrator::sentenceRandom(int seed)
{
    if(seed == 0) srand(timerRand.elapsed());
    else srand(seed);


     ;

    int n = rand() % totalCharInFile ;

    // seek to n characters
    // seeking ??
    sentenceFile.seekg(n);

    std::string res;

    // take one string and discard it, becuase it might have incomplete line
    std::getline(sentenceFile, res);

    std::getline(sentenceFile, res);

    return QString::fromStdString(res);

}

void SentenceGenrator::resetDefaults()
{
    // nothing for now
    sentenceFileName = SENTENCES_FILE_1;
    nLines = NUM_LINES_1 - 2 ;
    minWordChar = MIN_CHAR_LINE_1 ;

    totalCharInFile = nLines * minWordChar ; // may be aoverflow ?????????? Scalability ?


}

void SentenceGenrator::openFile()
{
    sentenceFile = std::ifstream(sentenceFileName) ;
}
