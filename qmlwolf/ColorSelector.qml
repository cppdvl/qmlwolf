import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    width: parent.width
    height: parent.height
    property alias colorselection: root.colorselection
    Rectangle {
        id:root
        width: parent.width * 0.90
        height: parent.height * 0.90
        anchors.centerIn: parent
        color: "transparent"
        border.color: "black"
        property color colorselection: Qt.rgba(redSlider.value, greenSlider.value, blueSlider.value, opacitySlider.value)

        ColumnLayout {
            width: parent.width
            PropertySlider {
                id: redSlider
                label: "Red"
            }
            PropertySlider {
                id: greenSlider
                label: "Green"

            }
            PropertySlider {
                id: blueSlider
                label: "Blue"
            }
            PropertySlider {
                id: opacitySlider
                label: "Opacity"
                value: 1.0
            }
        }
    }
}
