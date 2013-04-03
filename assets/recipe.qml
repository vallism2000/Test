import bb.cascades 1.0
import bb.platform 1.0
import bb.system 1.0

Page {
    id: recipePage
    titleBar: TitleBar {
        title: "Drink Recipe"
    }
    Container {
        layout: StackLayout {
        }
        attachedObjects: [
            SystemToast {
                id: myQmlToast
                body: "Recipe Deleted"
                onFinished: {
                    TestObject.removeRecipe();
                    nav.pop();
                }
            },
            SystemToast {
                id: myAddToast
                body: "Ingredients Added"
                onFinished: {
                    TestObject.addIngredientsToShoppingList();
                }
            },
            SystemDialog {
                id: deletionConfirmDialog
                title: "Confirm Deletion"
                body: "Are you sure you want to delete this recipe?"
                onFinished: {
                    if (deletionConfirmDialog != SystemUiResult.CancelButtonSelection) myQmlToast.show();
                }
            },
            SystemDialog {
                id: additionConfirmDialog
                title: "Confirm Addition"
                body: "Are you sure you want to add the ingredients from this recipe to your shopping list?"
                onFinished: {
                    if (additionConfirmDialog != SystemUiResult.CancelButtonSelection) myAddToast.show();
                }
            }
        ]
        preferredWidth: 90.0
        TextArea {
            id: displayName
            text: "Recipe Name"
            editable: false
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
            textStyle {
                fontSize: FontSize.XXLarge
                fontWeight: FontWeight.W500
            }
            onCreationCompleted: {
                displayName.setText(TestObject.getRecipeName());
            }
        }
        RatingIndicator {
            rating: TestObject.getRecipeRating()
        }
        TextArea {
            id: displayInfo
            text: "Recipe Information"
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
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
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
            editable: false
            onCreationCompleted: {
                displayIngredients.setText(TestObject.getIngredientsText());
            }
        }
        TextArea {
            id: displayInstructions
            editable: false
            text: "Instructions"
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
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
        },
        ComponentDefinition {
            id: editPageDefinition
            source: "editRecipe.qml"
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
        },
        ActionItem {
            id: del
            title: "Remove"
            imageSource: "asset:///ic_delete.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                deletionConfirmDialog.show();
            }
        },
        ActionItem {
            id: addToShopping
            title: "Add To Shopping List"
            imageSource: "asset:///ic_shoplist.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                additionConfirmDialog.show();
            }
        },
        ActionItem {
            id: edit
            title: "Edit Recipe"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                var page = editPageDefinition.createObject();
                nav.push(page);
            }
        }
    ]
}
