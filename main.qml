import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    Text{
        anchors.centerIn: parent
        text: adbLauncher.camId + "d"
    }

    Button{
        anchors.left: parent.left
        anchors.top: parent.top
        onClicked: {
            adbLauncher.callAdb()
        }
        text:"detect camera"
    }

}
