/*
             VARIABLE_IDENTIFIER        OBJECTNAME (QML)        FUNCTIONALITY
        i.    pomodomodeButton          _pomodoroMode          - for pomodoro
        ii.   shortBreakButton          _shortBreakMode        - for short break
        iii.  longBreakButton           _longBreakMode         - for long break
        iv.   timeRectangle             _timeRectangle         - for rectangle
        v.    timeText                  _timeText              - for time text
        vi.   timerButton               _startPauseResume      - for the Start/Pause/Resume button
        vii.  timerButtonText           _buttonStateText       - for the button state text
        viii. resetButton               _resetButton           - for the reset button
*/

#include "pomodoro.h"

#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <QTimer>

Pomodoro::Pomodoro(QObject *parent, QObject *uiWindowPtr) : QObject(parent), uiWindow(uiWindowPtr)
{
    //assigning button pointers of type QObject
    pomodomodeButton = uiWindowPtr->findChild<QObject*>("_pomodoroMode");
    shortBreakButton = uiWindowPtr->findChild<QObject*>("_shortBreakMode");
    longBreakButton = uiWindowPtr->findChild<QObject*>("_longBreakMode");
    timerButton = uiWindowPtr->findChild<QObject*>("_startPauseResume");
    resetButton = uiWindowPtr->findChild<QObject*>("_resetButton");

    //assigning the UI elements
    timerButtonText = uiWindowPtr->findChild<QQuickItem*>("_buttonStateText");
    timeRectangle = uiWindowPtr->findChild<QQuickItem*>("_timeRectangle");
    timeText = uiWindowPtr->findChild<QQuickItem*>("_timeText");

    //create a QTimer object
    countDown = new QTimer();

    //connect statement for mode setting buttons
    QObject::connect(pomodomodeButton, SIGNAL(clicked()), this, SLOT(setModePomodoro()));
    QObject::connect(shortBreakButton, SIGNAL(clicked()), this, SLOT(setModeShortBreak()));
    QObject::connect(longBreakButton, SIGNAL(clicked()), this, SLOT(setModeLongBreak()));

    //start button with timer
    QObject::connect(timerButton, SIGNAL(clicked()), this, SLOT(timerTriggered()));
    QObject::connect(countDown, SIGNAL(timeout()), this, SLOT(displayTimeUpdate()));

    //reset button
    QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(resetTimer()));
}

void Pomodoro::setModePomodoro()
{
    m_mode = Modes::Pomodoro_;

    countDown->stop();
    timerRunning = false;
    timerButtonText->setProperty("text", "Start");

    pomodomodeButton->setProperty("checked", "true");
    shortBreakButton->setProperty("checked", "false");
    longBreakButton->setProperty("checked", "false");
    timeRectangle->setProperty("color", "#A65151");

    timeTracker = POMODORO + 1;
    displayTimeUpdate();
    qDebug()<<"Time set to" <<timeTracker;
}

void Pomodoro::setModeShortBreak()
{
    m_mode = Modes::Short_break_;

    countDown->stop();
    timerRunning = false;
    timerButtonText->setProperty("text", "Start");

    pomodomodeButton->setProperty("checked", "false");
    shortBreakButton->setProperty("checked", "true");
    longBreakButton->setProperty("checked", "false");
    timeRectangle->setProperty("color", "#5994CD");

    timeTracker = SHORTBREAK + 1;
    displayTimeUpdate();
    qDebug()<<"Time set to" <<timeTracker;
}

void Pomodoro::setModeLongBreak()
{
    m_mode = Modes::Long_break_;

    countDown->stop();
    timerRunning = false;
    timerButtonText->setProperty("text", "Start");

    pomodomodeButton->setProperty("checked", "false");
    shortBreakButton->setProperty("checked", "false");
    longBreakButton->setProperty("checked", "true");
    timeRectangle->setProperty("color", "#79B77D");

    timeTracker = LONGBREAK + 1;
    displayTimeUpdate();
    qDebug()<<"Time set to" <<timeTracker;
}

void Pomodoro::timerTriggered()
{
    if(timerRunning == false)
    {
        countDown->start(1000);
        timerRunning = true;
        timerButtonText->setProperty("text", "Pause");
        resetButton->setProperty("visible", "false");
    }

    else if(timerRunning == true)
    {
        countDown->stop();
        timerRunning = false;
        if(timeTracker == 1500 || timeTracker == 900 ||timeTracker == 300)
        {
            timerButtonText->setProperty("text", "Start");
            resetButton->setProperty("visible", "false");
        }
        else
        {
            timerButtonText->setProperty("text", "Resume");
            resetButton->setProperty("visible", "true");
        }

    }


}

void Pomodoro::displayTimeUpdate()
{
    --timeTracker;
    int minutes = timeTracker / 60;
    int seconds = timeTracker % 60;
    QString timeString = QString::asprintf("%02d : %02d", minutes, seconds);
    timeText->setProperty("text", timeString);
}

void Pomodoro::resetTimer()
{
    if(m_mode == Modes::Pomodoro_)
    {
        countDown->stop();
        timeTracker = POMODORO + 1;
        timerButtonText->setProperty("text", "Start");
        resetButton->setProperty("visible", "false");
        displayTimeUpdate();
    }

    else if(m_mode == Modes::Short_break_)
    {
        countDown->stop();
        timeTracker = SHORTBREAK + 1;
        timerButtonText->setProperty("text", "Start");
        resetButton->setProperty("visible", "false");
        displayTimeUpdate();
    }

    else if(m_mode == Modes::Long_break_)
    {
        countDown->stop();
        timeTracker = LONGBREAK + 1;
        timerButtonText->setProperty("text", "Start");
        resetButton->setProperty("visible", "false");
        displayTimeUpdate();
    }
}
