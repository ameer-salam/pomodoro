import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

/*
  Objects

  1. Mode button object
    i.   _pomodoroMode          - for pomodoro
    ii.  _shortBreakMode        - for short break
    iii. _longBreakMode         - for long break

  2. Time display
    i.   _timeRectangle         - for rectangle
    ii.  _timeText              - for time text

  3. Time toggle button
    i.  _startPauseResume       - for the Start/Pause/Resume button
    ii. _buttonStateText        - for the button state text

  4. reset button
    i. _resetButton             - for the reset button
  */


Window {
    visible: true
    maximumHeight: 600
    minimumHeight: 600
    maximumWidth: 350
    minimumWidth: 350

    title: "Pomodoro by Ameer Salam"

    Column{
        id: _columnArea
        anchors.centerIn: parent
        spacing: 16

        Row{
            id: _modeRowArea
            spacing: 18

            Button{
                id: _pomodoroMode
                objectName: "_pomodoroMode"
                width: 88
                height: 88

                checkable: true
                checked: true

                Text{
                    anchors{
                        centerIn: parent
                    }
                    id: _pomodoroModeText
                    text: "Pomodoro"
                    font.pixelSize: 16
                    font.bold: true
                    rotation: -45
                    color: "#A65151"
                }
            }

            Button{
                id: _shortBreakMode
                objectName: "_shortBreakMode"
                width: 88
                height: 88

                checkable: true
                checked: false

                Text{
                    anchors{
                        centerIn: parent
                    }
                    id: _shortBreakModeText
                    text: "Short Break"
                    font.pixelSize: 16
                    font.bold: true
                    rotation: -45
                    color: "#5994CD"
                }
            }

            Button{
                id: _longBreakMode
                objectName: "_longBreakMode"
                width: 88
                height: 88

                checkable: true
                checked: false

                Text{
                    anchors{
                        centerIn: parent
                    }
                    id: _longBreakModeText
                    text: "Long Break"
                    font.pixelSize: 15
                    font.bold: true
                    rotation: -45
                    color: "#79B77D"
                }
            }
        }

        Rectangle{
            id: _timeRectangle
            objectName: "_timeRectangle"
            width: 300
            height: 130
            color: "#A65151"
            radius: 2
            border.color: "black"
            border.width: 1

            Text {
                id: _timeText
                objectName: "_timeText"
                text: "25:00"
                anchors.centerIn: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 62
                font.bold: true
            }
        }

        Row{
            id: _runningAndReset
            spacing: 16

            Button{
                id: _startPauseResumeButton
                objectName: "_startPauseResume"
                width: getWidth()
                height: 88

                Text{
                    id: _buttonStateText
                    objectName: "_buttonStateText"
                    text: "Start"
                    font.pixelSize: 16
                    font.bold: true
                    anchors.centerIn: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

            }

            Button
            {
                id: _resetButton
                objectName: "_resetButton"
                height: 88
                width: 88
                visible: false

                Text{
                    text: "Reset"
                    font.pixelSize: 15
                    font.bold: true
                    anchors.centerIn: parent
                }
            }
        }
    }

    function getWidth()
    {
        if(_resetButton.visible === true)
        {
            return 196
        }
        else
            return 300
    }
}
