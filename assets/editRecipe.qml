import bb.cascades 1.0
import bb.platform 1.0
import bb.system 1.0

Page {
    id: editRecipePage
    titleBar: TitleBar {
        title: "Drink Recipe"
    }
    Container {
        layout: StackLayout {}
        
        TextArea {
            id: editName
            objectName: "editName"
            text: "Recipe Name"
            editable: true
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
            textStyle {
                fontSize: FontSize.XXLarge
                fontWeight: FontWeight.W500
            }
            onCreationCompleted: {
                editName.setText(TestObject.getRecipeName());
            }
        }
        RatingIndicator {
            rating: TestObject.getRecipeRating()
        }
        TextArea {
            id: editInfo
            objectName: "editInfo"
            text: "Recipe Information"
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
            textStyle {
                fontStyle: FontStyle.Italic
            }
            editable: true
            onCreationCompleted: {
                editInfo.setText(TestObject.getRecipeInfo());
                TestObject.getIngredients();
            }
        }
        TextArea {
            id: editInstructions
            objectName: "editInstructions"
            editable: true
            text: "Instructions"
            inputMode: TextAreaInputMode.Text
            input.flags: TextInputFlag.SpellCheckOff
            onCreationCompleted: {
               editInstructions.setText(TestObject.getInstructions());
            }
            leftPadding: 20.0
            rightPadding: 20.0
        }
        ScrollView {
            Container {
                TextArea {
                    id: ing11
                    objectName: "ing11"
                    hintText: "Ingredient 1"
                    onCreationCompleted: {
                        ing11.setText(TestObject.getIngredientTextAt(0));
                    }
                }
                TextArea {
                    id: ing12
                    objectName: "ing12"
                    hintText: "Amount of Ingredient 1"
                    onCreationCompleted: {
                        ing12.setText(TestObject.getIngredientQuantityTextAt(0));
                    }
                }
                TextArea {
                    id: ing21
                    objectName: "ing21"
                    hintText: "Ingredient 2"
                    onCreationCompleted: {
                        ing21.setText(TestObject.getIngredientTextAt(1));
                    }
                }
                TextArea {
                    id: ing22
                    objectName: "ing22"
                    hintText: "Amount of Ingredient 2"
                    onCreationCompleted: {
                        ing22.setText(TestObject.getIngredientQuantityTextAt(1));
                    }
                }
                TextArea {
                    id: ing31
                    objectName: "ing31"
                    hintText: "Ingredient 3"
                    onCreationCompleted: {
                        ing31.setText(TestObject.getIngredientTextAt(2));
                    }
                }
                TextArea {
                    id: ing32
                    objectName: "ing32"
                    hintText: "Amount of Ingredient 3"
                    onCreationCompleted: {
                        ing32.setText(TestObject.getIngredientQuantityTextAt(2));
                    }
                }
                TextArea {
                    id: ing41
                    objectName: "ing41"
                    hintText: "Ingredient 4"
                    onCreationCompleted: {
                        ing41.setText(TestObject.getIngredientTextAt(3));
                    }
                }
                TextArea {
                    id: ing42
                    objectName: "ing42"
                    hintText: "Amount of Ingredient 4"
                    onCreationCompleted: {
                        ing42.setText(TestObject.getIngredientQuantityTextAt(3));
                    }
                }
                TextArea {
                    id: ing51
                    objectName: "ing51"
                    hintText: "Ingredient 5"
                    onCreationCompleted: {
                        ing51.setText(TestObject.getIngredientTextAt(4));
                    }
                }
                TextArea {
                    id: ing52
                    objectName: "ing52"
                    hintText: "Amount of Ingredient 5"
                    onCreationCompleted: {
                        ing52.setText(TestObject.getIngredientQuantityTextAt(4));
                    }
                }
            }
        }
    }
    actions: [
        ActionItem {
            id: save
            title: "Save"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///ic_save.png"
            onTriggered: {
                TestObject.modRecipe();
                nav.pop();
                nav.pop();
            }
        }
    ]
}
