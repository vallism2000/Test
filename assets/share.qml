import bb.cascades 1.0

Page {
    id: sharePage
      signal updateMessage(string message, string dataType)
      signal enableDataSharing()
      signal disableSharing()
    
    titleBar: TitleBar {
        title: "Share Recipe"
    }
    Container {
        layout: StackLayout {}
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
            onTriggered: {
                var selectedItem = dataModel.data(indexPath);
                console.log("Selected " + selectedItem.name);
                _nfcHandlerObject.enableDataSharing();
                _shareObject.triggerShareEvent(selectedItem.name);
                
            }
        }
    }
    
    paneProperties: NavigationPaneProperties {
                backButton: ActionItem {     
                    onTriggered: {
                        _nfcHandlerObject.disableSharing();
                        nav.pop();
                        console.log("clear share hopefully");
                    }
                }
            }
}