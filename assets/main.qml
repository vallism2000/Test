import bb.cascades 1.0

NavigationPane {
    id: nav
    Page {
        id: mainPage
        Container {
            layout: StackLayout {}
            Label {
                id: titleLabel
                text: qsTr("DrinkIt App")
                textStyle.base: SystemDefaults.TextStyles.BigText
            }
            TextField {
                id: searchText
                input.submitKey: SubmitKey.Search
                hintText: "Search by Alcohol"
                onTextChanged: {
                    if (searchText.text == "") {
                        titleLabel.text = "DrinkIt App";
                        TestObject.getFullList();
                    }
                    else {
                        titleLabel.text = "Searching for: " + searchText.text;
                        TestObject.getSearchedList();
                    }
                }
            }
            ListView {
                id: recipeList
                objectName: "recipeList"
                dataModel: recipeName
                layout: StackListLayout {}
                attachedObjects: [
                    ArrayDataModel {
                        id: recipeID
                        objectName: "recipeID"
                    },
                    ArrayDataModel {
                        id: recipeName
                        objectName: "recipeName"
                    }
                ]
                onTriggered: {
                    select(indexPath);
                    
                    var page = recipePageDefinition.createObject();
                    nav.push(page);
                }
                onSelectionChanged: {
                    if (selected) {
                        //
                    }
                }
            }
        }
        attachedObjects: [
            ComponentDefinition {
                id: recipePageDefinition
                source: "recipe.qml"
            }
        ]
    }
    onTopChanged: {
        if (page == mainPage) {
            recipeList.clearSelection();
        }
    }
    onPopTransitionEnded: {
        page.destroy();
    }
}
