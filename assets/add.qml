import bb.cascades 1.0

Page {
    id: addPage
    titleBar: TitleBar {
        title: "Add New Recipe"
    }
    Container {
        layout: StackLayout {}
        
        TextArea {
            id: displayName
            hintText: "Recipe Name"
            onCreationCompleted: {
                //
            }
        }
        TextArea {
            id: displayInfo
            hintText: "Recipe Information"
            onCreationCompleted: {
                //
            }
        }
        Button {
            text: "Save Recipe"
        }
    }
}