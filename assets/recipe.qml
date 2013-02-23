import bb.cascades 1.0

Page {
    id: recipePage
    Container {
        layout: StackLayout {}
        Label {
            id: displayName
            text: "Recipe Name"
        }
        TextArea {
            id: displayInfo
            text: "Recipe Information"
            editable: false
        }
    }
}