import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    property alias fov: root.fov
    Rectangle {
        id:root
        width: parent.width * 0.90
        height: parent.height * 0.90
        anchors.centerIn: parent
        color: "transparent"
        border.color: "black"
        property alias fov: fovSlider.value

        ColumnLayout {
            width: parent.width
            Layout.alignment: Qt.AlignVCenter
            PropertySlider {
                id: fovSlider
                label: "Fov"
                to: 120
                from: 30
            }
        }
    }
}
