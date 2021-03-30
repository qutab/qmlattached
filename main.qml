import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import com.ge.sigblocker 1.0
import "util.js" as Util

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function block() {
        dataMap.SignalBlocker.enabled = true // Question: How can I use attached property SignalBlocker.enabled for dataMap?
    }
    function unblock() {
        dataMap.SignalBlocker.enabled = false
    }

    Text {
        id: textField
        text: block(), "click count: " + Util.getData("person").name

        Component.onCompleted: unblock()
    }
}
