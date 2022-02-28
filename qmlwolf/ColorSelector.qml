import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id:root
    width: parent.width
    color: "transparent"
    border.color: "red"
    property color colorselection: Qt.rgba(redSlider.value, greenSlider.value, blueSlider.value, opacitySlider.value)

    ColumnLayout {
        width: parent.width
        PropertySlider {
            id: redSlider
            label: "red"

        }
        PropertySlider {
            id: greenSlider
            label: "green"

        }
        PropertySlider {
            id: blueSlider
            label: "blue"
        }
        PropertySlider {
            id: opacitySlider
            label: "opacity"
            value: 1.0
        }
    }
}
