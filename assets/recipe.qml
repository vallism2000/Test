import bb.cascades 1.0

Page {
    id: recipePage
    titleBar: TitleBar {
        title: "Drink Recipe"
    }
    Container {
        layout: StackLayout {}
        preferredWidth: 90.0
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
                TestObject.getIngredients();
            }
        }
 
        TextArea {
            id: displayIngredients
            text: "ingredients"
            editable: false
            onCreationCompleted: {
                 displayIngredients.setText(TestObject.getIngredientsText());

             }
            
        }
        
        TextArea{
         id: displayInstructions
         editable: false
         text: "Instructions"
         onCreationCompleted: {
             displayInstructions.setText(TestObject.getInstructions());
         }
            leftPadding: 20.0
            rightPadding: 20.0
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
                nav.push(page);
            }
        }
    ]
}