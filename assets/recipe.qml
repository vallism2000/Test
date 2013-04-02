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
          textStyle {
                fontSize: FontSize.XXLarge
                fontWeight: FontWeight.W500
          }
            onCreationCompleted: {
                displayName.setText(TestObject.getRecipeName());
            }

        }
        RatingIndicator{
            rating: TestObject.getRecipeRating()
        }
        TextArea {
            id: displayInfo
            text: "Recipe Information"
            textStyle {
                fontStyle: FontStyle.Italic
            }
            editable: false
            onCreationCompleted: {
                displayInfo.setText(TestObject.getRecipeInfo());
            }
        }
        
        TextArea {
            id: displayIngredients
            text: ""
            editable: false

        }

    }
    attachedObjects: [
        ComponentDefinition {
            id: sharePageDefinition
            source: "share.qml"
        }
    ]
    actions: [
        ActionItem {
            id: share
            title: "Share"
            imageSource: "asset:///ic_share.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            
            onTriggered: {
                var page = sharePageDefinition.createObject();
              
                // _shareObject.setRecipeID(TestObject.getRecipeID());
                 //_shareObject.setRecipeName(TestObject.getRecipeName());
                 //_shareObject.setRecipeDesc(TestObject.getRecipeInfo());
                 //_shareObject.setRecipeIngredients(TestObject.getIngredients());
                // _shareObject.setRecipeInstructions(TestObject.getInstructions());
                // _shareObject.setRating(TestObject.getRecipeRating());
                 
                nav.push(page);
            }
        }
    ]
}