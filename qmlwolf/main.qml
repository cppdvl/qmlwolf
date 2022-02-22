import QtQuick 2.15
import QtQuick.Window 2.15

import jguarin.opengl.renderer 1.0


Window {
    id: root
    width: 1600
    height: 1000
    visible: true
    property color rectanglecolor: "deepskyblue";
    Rectangle{
        id: qmlRectangle
        width: 400
        height: 400
        anchors.centerIn: parent
        QMLWOLFScene
        {
            id: openglRectangle
            anchors.fill : parent
            onRenderingBackendInitialized :

                () => {
                    console.log("Rendering Backend Initialized!!!");
                }
        }
    }


}
