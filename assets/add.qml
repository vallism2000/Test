import bb.cascades 1.0

Page {
    id: addPage
    titleBar: TitleBar {
        title: "Add New Recipe"
    }
    Container {
        layout: StackLayout {}
        //Label {
        //    text: "Add Function Not Enabled"
        //    horizontalAlignment: HorizontalAlignment.Center
        //    textStyle.textAlign: TextAlign.Center
        //}
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
            onClicked: {
                TestObject.submitRecipe();
                nav.pop();
            }
        }
    }
}