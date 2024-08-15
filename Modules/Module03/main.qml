import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import ListControl 1.0

Window {
    width: 1000
    height: 480
    visible: true
    color: "#4f4f4f"
    title: qsTr("Hello World")

    ListControlModel{
        id: listcontrol
    }

    Text {
        id: _text
        x: 857
        y: 241
        color: "#c0c0c0"
        text: qsTr("Name")
        font.pixelSize: 15
        rotation: 1.079
        font.family: "Tahoma"
    }

    Text {
        id: _text1
        x: 855
        y: 315
        width: 98
        height: 21
        color: "#c0c0c0"
        text: qsTr("Phone Number")
        font.pixelSize: 15
        font.family: "Tahoma"
    }

    Text {
        id: _text2
        x: 859
        y: 381
        color: "#c0c0c0"
        text: qsTr("email")
        font.pixelSize: 15
        font.family: "Tahoma"
    }

    Rectangle{

        id: component_listView
        x:40
        y:60
        width:650
        height:380
        color: "white"
        radius: 0

        ListView {
            id: listView
            x: 0
            y: -20
            width: 650
            height: 400
            snapMode: ListView.NoSnap
            orientation: ListView.Vertical
            transformOrigin: Item.Center

            ScrollBar.vertical: ScrollBar{
                policy: ScrollBar.AlwaysOn
            }

            highlight: Rectangle{
                width: parent.width
                height: 40
                color: "lightBlue"
            }

            model: listcontrol.getModel()

            header: Row{
                height: 40

                Rectangle{
                    width:170
                    height:40
                    color: "#86a6a4"
                    Text {
                        color: "#005555"
                        anchors.centerIn: parent
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        text: "Name"
                    }
                }
                Rectangle{
                    width:200
                    height:40
                    color: "#86a6a4"
                    Text {
                        color: "#005555"
                        anchors.centerIn: parent
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        text: "Number"
                    }
                }
                Rectangle{
                    width:275
                    height:40
                    color: "#86a6a4"
                    Text {
                        color: "#005555"
                        anchors.centerIn: parent
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        text: "E-mail"
                    }
                }
            }

            delegate: Rectangle{
                border.width: 1
                border.color: "gray"
                color: "transparent"
                width: 650
                height: 40

                MouseArea{
                    id: listmouse
                    anchors.fill: parent
                    onClicked: {
                        listView.currentIndex = index
                        listcontrol.selectRow(index)
                        console.log("index: " + index )
                    }
                }

                Row{
                    Text {
                        padding: 5
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        width: 170
                        text: model.name
                    }
                    Text{
                        padding: 5
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        width: 200
                        text: model.number
                    }
                    Text{
                        padding: 5
                        font.pixelSize: 17
                        font.family: "Tahoma"
                        width: 275
                        text: model.email
                    }
                }
            }
        }
    }

    Rectangle { //edit the contents button
        id: editing
        x: 855
        y: 180
        width: 105
        height: 45
        color: "#86a6a4"
        Text {
            id: _text5
            color: "#005555"
            text: qsTr("EDIT")
            font.pixelSize: 25
            rotation: 0
            font.family: "Tahoma"
            anchors.centerIn: parent
        }

        TapHandler {
            onTapped: {
                if (listView.currentIndex >= 0){
                    listcontrol.edit(listView.currentIndex, namefield.text, numberfield.text, emailfield.text)
                }
            }
        }
    }
    Rectangle {  //add the contents button
        id: adding
        x: 855
        y: 40
        width: 105
        height: 45
        color: "#86a6a4"

        Text {
            id: _text3
            anchors.centerIn: parent
            color: "#005555"
            text: qsTr("ADD")
            font.pixelSize: 25
            rotation: 0
            font.family: "Tahoma"
        }

        TapHandler {
            onTapped: {
                listcontrol.add(namefield.text, numberfield.text, emailfield.text)
            }
        }
    }

    Rectangle { //delete the contents button
        id: deleting
        x: 855
        y: 110
        width: 105
        height: 45
        color: "#86a6a4"

        Text {
            id: _text4
            anchors.centerIn: parent
            color: "#005555"
            text: qsTr("DELETE")
            font.pixelSize: 25
            rotation: 0
            font.family: "Tahoma"
        }

        TapHandler {
            onTapped:{
                if (listView.currentIndex >= 0){
                    listcontrol.remove(listView.currentIndex)
                    listView.currentIndex = -1
                    listcontrol.selectRow(-1)
                }
            }
        }
    }

    TextField { //namefield textfield
        id: namefield
        x: 760
        y: 267
        width: 200
        height: 25
        color: "#ffffff"
        text: listcontrol.nowName
        verticalAlignment: Text.AlignVCenter
        placeholderTextColor: "transparent"
        font.family: "Tahoma"

        background: Rectangle {
            color: "#86a6a4"
            height: 1
            width: parent.width
            anchors.bottom: parent.bottom
        }
    }

    TextField {  //numberfield textfield
        id: numberfield
        x: 760
        y: 342
        width: 200
        height: 25
        color: "#ffffff"
        text: listcontrol.nowNumber
        verticalAlignment: Text.AlignVCenter
        placeholderTextColor: "#80ffffff"
        font.family: "Tahoma"

        background: Rectangle {
            width: parent.width
            height: 1
            color: "#86a6a4"
            anchors.bottom: parent.bottom
        }
    }

    TextField { //emailfield textfield
        id: emailfield
        x: 760
        y: 406
        width: 200
        height: 25
        color: "#ffffff"
        text: listcontrol.nowEmail
        verticalAlignment: Text.AlignVCenter
        placeholderTextColor: "#80ffffff"
        font.family: "Tahoma"

        background: Rectangle {
            width: parent.width
            height: 1
            color: "#86a6a4"
            anchors.bottom: parent.bottom
        }
    }

    Text {
        id: howmany
        x: 705
        y: 46
        width: 60
        height: 28
        color: "#ffffff"
        text: qsTr(listView.currentIndex + 1 + "/" + listcontrol.len)
        font.pixelSize: 20
        font.family: "Tahoma"
    }

}
