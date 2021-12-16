#include "settingswindow.h"

SettingsWindow::SettingsWindow()
{
    this->setWindowTitle("Settings");
    this->resize(OTHER_WIN_SIZEX, OTHER_WIN_SIZEY) ;
    setUpUI();
}

void SettingsWindow::linkParent(StartMenu *win)
{
    this->parentWin = win ;
}

void SettingsWindow::setUpUI()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QPushButton* resetBtn = new QPushButton("Reset");

    mainLayout->addWidget(resetBtn);

    connect(resetBtn, &QPushButton::clicked, this, &SettingsWindow::resetData);

}

void SettingsWindow::resetData()
{
    parentWin->resetUserData();
}
