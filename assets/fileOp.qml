import bb.cascades 1.0

Page {
    id: fileOpPage
    titleBar: TitleBar {
        title: "Save/Load Demo"
    }
    Container {
        layout: StackLayout {}
        
        TextArea {
            id: saveText
            hintText: "Text to Save"
            onCreationCompleted: { }
        }
        Button {
            text: "Save"
            
            onClicked: {
                TestObject.saveJSON(saveText.text);
                outputLabel.text = "Saving '" + saveText.text + "' to file.";
            }
        }
        Button {
            text: "Load"
            
            onClicked: {
                var loadedString = TestObject.loadJSON();
                outputLabel.text = "Loaded '" + loadedString + "' from file.";
            }
        }
        Label {
            id: outputLabel
            text: qsTr("Output Here");
            horizontalAlignment: HorizontalAlignment.Center
            textStyle.textAlign: TextAlign.Center
        }
    }
}