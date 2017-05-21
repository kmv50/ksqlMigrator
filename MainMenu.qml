import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    height: parent.height-30;
    width: 200;
    x: -200;
    anchors.bottom: parent.bottom;
    id:_panelMain
    Rectangle{
        anchors.fill: parent
        color: '#eeeeee'
        Rectangle{
            width: parent.width-30;
            height: parent.height-30;
            anchors.centerIn: parent;
            color: "transparent"
            Column{
                anchors.fill: parent
                Button{
                   width: parent.width
                   height: 30
                   text: "Sql"

                }
                Button{
                   width: parent.width
                   height: 30
                   text: "Compare"
                   onClicked: {

                       panelHide();
                   }
                }

                Button{
                   width: parent.width
                   height: 30
                   text: "Setting"
                   onClicked: {
                       _MainCpp.ShowSettings();
                       panelHide();
                   }
                }

            }
        }

    }

    NumberAnimation {
        id: showAnimation
        target: _panelMain
        property: "x"
        from: -200
        to: 0
        duration: 500
    }

    NumberAnimation {
        id: hideAnimation
        target: _panelMain
        property: "x"
        from: 0
        to: -200
        duration: 500
    }

    property bool menuState : true


    function panelAction(){
        if(menuState){
            panelShow();
        }else{
            panelHide();
        }

    }

    function panelHide(){
        hideAnimation.start();
        menuState = true;
    }


    function panelShow(){
        showAnimation.start();
        menuState = false;
    }
}
