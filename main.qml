import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Ksql Migrator")

    id: masterPage
        background: Rectangle {
            Image{
                anchors.fill: parent
                source: 'qrc:/Resources/bg_dotted.gif'
                fillMode: Image.Tile
            }
        }
        Rectangle{
            anchors.top: parent.top;
            anchors.topMargin:  40;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 10;
            anchors.right: parent.right;
            anchors.rightMargin: 40;
            anchors.left: parent.left;
            anchors.leftMargin: 40;
            color: "white"
            opacity: 0.7
            Loader{
                objectName: 'MainLayout'
                anchors.fill: parent
            }
        }
        MainMenu{
            id: masterMenu
        }
        MainHeader{

        }

    MessageDialog{
        id: mainDialog
        modality: Qt.WindowModal
        onAccepted: Qt.quit()
    }

    function showMessageBox(title,msn){
        mainDialog.text = msn;
        mainDialog.title = title;
        mainDialog.open();
    }

}
