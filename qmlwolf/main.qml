import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12


import jguarin.opengl.renderer 1.0
Window {
    id: root
    width: 1600
    height: 1000
    visible: true
    property color rectanglecolor: "deepskyblue";


    ColumnLayout{
        width: 800
        anchors.centerIn: parent
        spacing: 5
        Rectangle{
            id: qmlRectangle
            width: parent.width
            height: 500

            QMLWOLFScene
            {
                // @disable-check M16
                id: openglRectangle
                anchors.fill : parent
                onRenderingBackendInitialized :

                    () => {
                        console.log("Rendering Backend Initialized!!!");
                    }
            }
        }
        RowLayout {
            width: parent.width
            height: 60
            spacing: 0
            ColorSelector{
                id: colorSelector
                width: parent.width * .5
                height: parent.height
                onColorselectionChanged: () => { openglRectangle.setBackgroundColor(colorselection); }
            }
            ColorSelector{
                id: colorSelector2
                width: parent.width * .5
                height: parent.height
            }

        }



    }

}





