import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    width: parent.width;
    height: 30;
    Rectangle{
        id: rectangle
        anchors.fill: parent
        color: '#428bca'

        Image {
                    id: btn_Menu
                    width: 50;
                    height: 20
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    source: "qrc:/Resources/mobile-nav.png"
                    fillMode: Image.PreserveAspectFit
                    MouseArea{
                        anchors.fill: parent
                        id: btnmenu
                        onClicked: {
                            masterMenu.panelAction();
                        }
                    }
                }

    }


}
