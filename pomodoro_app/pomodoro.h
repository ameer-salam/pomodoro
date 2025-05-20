#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QQuickItem>
#include <QTimer>

#define POMODORO 1500
#define LONGBREAK 900
#define SHORTBREAK 300

class Pomodoro : public QObject
{
    Q_OBJECT
public:
    explicit Pomodoro(QObject *parent = 0, QObject *uiWindowPtr = nullptr);

    //enum for modes
    enum class Modes{
        Pomodoro_,
        Short_break_,
        Long_break_
    };

signals:

public slots:

    //these function is to set the mode
    void setModePomodoro();
    void setModeShortBreak();
    void setModeLongBreak();

    //to start and pause the timer
    void timerTriggered();

    //to update the time and display
    void displayTimeUpdate();

    //to reset the timer
    void resetTimer();

private:
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

    //QObjects
    QObject *uiWindow = nullptr,
            *pomodomodeButton = nullptr,
            *shortBreakButton = nullptr,
            *longBreakButton = nullptr,
            *timerButton = nullptr,
            *resetButton = nullptr;

    //QQuickItems
    QQuickItem *timeRectangle = nullptr,
               *timeText = nullptr,
               *timerButtonText = nullptr;

    //QTImer Object
    QTimer *countDown = nullptr;

    //to store previous mode
    Modes m_mode = Modes::Pomodoro_;

    //time tracker and state
    int timeTracker = POMODORO;
    bool timerRunning = false;
};

#endif // POMODORO_H
