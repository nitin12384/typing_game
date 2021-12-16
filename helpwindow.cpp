#include "helpwindow.h"

HelpWindow::HelpWindow()
{
    this->setWindowTitle("Help") ;
    this->resize(OTHER_WIN_SIZEX, OTHER_WIN_SIZEY) ;

    setUpUI();
    setHelpText();
}

void HelpWindow::setUpUI()
{
    // Select type of layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);


    helpTxt = new QTextEdit();
    helpTxt->setReadOnly(true);

    mainLayout->addWidget(helpTxt);

}

void HelpWindow::setHelpText()
{
    QFile helpFile(HELP_FILE_NAME) ;

    bool success = helpFile.open(QIODevice::ReadOnly | QIODevice::Text) ;

    if(! success){
        helpTxt->setText(HELP_DEFAULT);
        return;
    }

    // Read whole file into a QString
    QString text = "";
    while( ! helpFile.atEnd()){
        text += helpFile.readLine() + "\n" ;
    }


    helpTxt->setText(text);



}
