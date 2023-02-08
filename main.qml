import QtQuick
import QtQuick.Controls
import workshop_test_project




Window {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property string rect1_color : "orange"

    TestKlasse{
        id:tk1
    }

    Connections {
        target: tk1
        function onColorChanged(p_color) {
            console.log("color: ", p_color);
            root.rect1_color = p_color;
        }
    }

    Button{
        id:bt_1
        anchors.centerIn: parent
        text: "button 1";
        onClicked: {
            tk1.onButtonClick();
        }
    }

    Rectangle {
        id: rect_1
        width: 100
        height: 100
        color: root.rect1_color
    }


}
