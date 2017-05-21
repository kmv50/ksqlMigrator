import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    anchors.fill: parent
    Flickable{
        id: flickable
        anchors.fill: parent
        ScrollIndicator.vertical: ScrollIndicator { }

    GroupBox {
        id: groupBox
        height: 225
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 40
        title: qsTr("Data Source 1")

        GridLayout {
            id: gridLayout
            anchors.bottomMargin: 10
            anchors.topMargin: 0
            anchors.fill: parent
            rowSpacing: 0
            anchors.margins: 10
            columns: 2
            rows: 4

            Text {
                id: text3
                text: qsTr("Servidor")
                rightPadding: 20
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: false
                font.pixelSize: 12
                Layout.row: 0
            }

            TextField {
                height: 25
                objectName: 'txt_Server1'
                Layout.column: 1
                Layout.row: 0
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pointSize: 8
                Layout.fillWidth: true
            }

            Text {
                id: text4
                text: qsTr("Usuario")
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
                Layout.row: 1

            }


            TextField {
                height: 25
                objectName: 'txt_usuario1'
                Layout.column: 1
                Layout.row: 1
                font.pointSize: 8
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

            }


            Text {
                id: text5
                text: qsTr("Contrasena")
                rightPadding: 10
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
                Layout.row: 2

            }


            TextField {
                objectName: 'txt_contrasena1'
                Layout.column: 1
                Layout.row: 2
                font.capitalization: Font.SmallCaps
                font.pointSize: 8
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                echoMode: TextInput.Password
            }

            Text {
                id: text6
                text: qsTr("Database")
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
                Layout.row: 3
            }

            Row{
                id: row
                Layout.column: 1
                Layout.row: 3
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                ComboBox {
                    anchors.right: btn_refrescar.left
                    anchors.rightMargin: 10
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    objectName: 'cb_db1'
                    font.pointSize: 8
                }
                Button{
                    id: btn_refrescar
                    text: 'Refrescar'
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    height: 30
                    width: 110
                    onClicked: {
                        _SettingsCpp.TestDatasource1();
                    }
                }
            }

        }




    }

    GroupBox {
        id: groupBox1
        x: -5
        y: 6
        height: 225
        anchors.rightMargin: 50
        anchors.right: parent.right
        anchors.leftMargin: 50
        title: qsTr("Data Source 2")
        anchors.top: parent.top
        GridLayout {
            id: gridLayout1
            rowSpacing: 0
            columns: 2
            anchors.margins: 10
            Text {
                id: text7
                text: qsTr("Servidor")
                Layout.row: 0
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: false
                font.pixelSize: 12
                rightPadding: 20
            }

            TextField {
                height: 25
                Layout.row: 0
                objectName: "txt_Server2"
                font.pointSize: 8
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                Layout.column: 1
            }

            Text {
                id: text8
                text: qsTr("Usuario")
                Layout.row: 1
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
            }

            TextField {
                height: 25
                Layout.row: 1
                objectName: "txt_usuario2"
                font.pointSize: 8
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                Layout.column: 1
            }

            Text {
                id: text9
                text: qsTr("Contrasena")
                Layout.row: 2
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
                rightPadding: 10
            }

            TextField {
                Layout.row: 2
                font.capitalization: Font.SmallCaps
                objectName: "txt_contrasena2"
                font.pointSize: 8
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                echoMode: TextInput.Password
                Layout.column: 1
            }

            Text {
                id: text10
                text: qsTr("Database")
                Layout.row: 3
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                font.pixelSize: 12
            }

            Row {
                id: row1
                Layout.row: 3
                Layout.fillHeight: true
                ComboBox {
                    anchors.rightMargin: 10
                    anchors.right: btn_refrescar2.left
                    anchors.leftMargin: 0
                    objectName: "cb_db2"
                    font.pointSize: 8
                    anchors.left: parent.left
                }

                Button {
                    id: btn_refrescar2
                    width: 110
                    height: 30
                    text: "Refrescar"
                    anchors.rightMargin: 0
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.top: parent.top
                    onClicked: {

                    }
                }
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                Layout.column: 1
            }
            anchors.topMargin: 0
            anchors.bottomMargin: 10
            rows: 4
            anchors.fill: parent
        }
        anchors.topMargin: 289
        anchors.left: parent.left
    }

    Button {
        id: button
        x: 518
        y: 572
        width: 200
        text: qsTr("Guardar")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 50
        onClicked: {
            _SettingsCpp.Save();
        }
    }
    }

}
