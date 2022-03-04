import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3


Rectangle {
    id:root
    property alias label: aSlider.label
    property alias value: aSlider.value
    property alias to: aSlider.to
    property alias from: aSlider.from
    width: parent.width
    height: 10
    signal propertySliderChanged()

    FloatSlider {
        width: parent.width
        anchors.verticalCenter: parent.verticalCenter
        id: aSlider
        label: ""
        onFloatSliderChanged: () => { propertySliderChanged(); }
    }

    component FloatSlider : RowLayout {
        width: parent.width
        property alias label: textSlider.text
        property int handleHeight: parent.height
        property alias value: sliderControl.value
        property alias from: sliderControl.from
        property alias to: sliderControl.to

        property real _width_ : .1375
        signal floatSliderChanged()
        Rectangle {
            id: textRectangle
            color: "transparent"
            width: parent.width * .1375
            height: sliderControl.height
            Text {
                id: textSlider
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
            }
        }

        Slider {
            id: sliderControl
            from: 0
            to: 1.0
            stepSize: 0.001
            implicitWidth: parent.width *  0.76
            onMoved : () => { parent.floatSliderChanged(); }
            Rectangle {
                color:"transparent"
                anchors.fill: parent
                border.color: "black"
            }

            background: Rectangle {
                x: sliderControl.leftPadding
                y: sliderControl.topPadding + sliderControl.availableHeight *.5 - height *.5
                implicitWidth: 200
                implicitHeight: 4
                width: sliderControl.availableWidth
                height: implicitHeight
                radius: 2
                color: "#bddebf"
                Rectangle {
                    width: sliderControl.visualPosition * parent.width
                    height: parent.height
                    color: "#21be2b"
                }
            }
            handle: Rectangle {

                x: sliderControl.leftPadding + sliderControl.visualPosition * (sliderControl.availableWidth - width)
                y: sliderControl.topPadding + sliderControl.availableHeight / 2 - height / 2
                implicitWidth: sliderControl.parent.handleHeight
                implicitHeight: sliderControl.parent.handleHeight
                radius: 2
                color: sliderControl.pressed ? "#f0f0f0" : "#f6f6f6"
                border.color: "#bdbebf"
            }

        }
        Rectangle {
            color: "transparent"
            width: parent.width * .1375 * .5
            height: sliderControl.height
            Text {
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                text: sliderControl.value.toFixed(3)
            }
        }
    }
}
