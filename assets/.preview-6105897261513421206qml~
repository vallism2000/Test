import bb.cascades 1.0

Page {
    id: recipePage
    titleBar: TitleBar {
        title: "Drink Recipe"
    }
    Container {
        layout: StackLayout {}
        TextArea {
            id: displayName
            text: "Recipe Name"
            editable: false
            onCreationCompleted: {
                displayName.setText(TestObject.getRecipeName());
            }
        }
        TextArea {
            id: displayInfo
            text: "Recipe Information"
            editable: false
            onCreationCompleted: {
                displayInfo.setText(TestObject.getRecipeInfo());
            }
        }
    }
}