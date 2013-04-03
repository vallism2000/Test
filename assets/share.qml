import bb.cascades 1.0
import bb.platform 1.0
import bb.system 1.0

Page {
    id: sharePage
    titleBar: TitleBar {
        title: "Share Recipe"
    }
    Container {
        layout: StackLayout {
        }
        Label {
            id: shareLabel
            text: "Select how to share this recipe:"
        }
        ListView {
            id: shareOptionsList
            dataModel: XmlDataModel {
                source: "models/shareoptions.xml"
            }
            listItemComponents: [
                ListItemComponent {
                    type: "option"
                    StandardListItem {
                        title: ListItemData.name
                    }
                }
            ]
            attachedObjects: [
                SystemDialog {
                    id: myQmlDialog
                    title: "Share Status:"
                    body: "Share Successful "
                    cancelButton.label: undefined
                }
            ]
            onTriggered: {
                var selectedItem = dataModel.data(indexPath);
                console.log("Selected " + selectedItem.name);
                _shareObject.triggerShareEvent(selectedItem.name);
                if (selectedItem.name == "Facebook") {
                    myQmlDialog.show()
                }
            }
        }
    }
}
