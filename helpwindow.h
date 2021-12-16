#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include "Qt_includes.h"


class HelpWindow : public QWidget
{
public:
    HelpWindow();

private:

    // Functions
    void setUpUI();
    void setHelpText();

    // UI variables
    QTextEdit* helpTxt;

};





#endif // HELPWINDOW_H
