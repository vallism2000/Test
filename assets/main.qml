import bb.cascades 1.0

TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: "Home"
		NavigationPane {
		    id: nav
		    objectName: "nav"
		    Page {
		        id: mainPage
		        titleBar: TitleBar {
		            id: titleLabel
		            title: "DrinkItApp"
		        }
		        Container {
		            layout: StackLayout {}
		            //Label {
		            //    id: titleLabel
		            //    text: qsTr("DrinkIt App")
		            //    textStyle.base: SystemDefaults.TextStyles.BigText
		            //    horizontalAlignment: HorizontalAlignment.Center
		            //    textStyle.textAlign: TextAlign.Center
		            //}
		            TextField {
		                id: searchText
		                input.submitKey: SubmitKey.Search
		                hintText: "Search by Alcohol"
		                onTextChanged: {
		                    if (searchText.text == "") {
		                        titleLabel.title = "DrinkItApp";
		                        TestObject.getFullList();
		                    }
		                    else {
		                        titleLabel.title = "Searching for: " + searchText.text;
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
		                        TestObject.getRecipe(indexPath, recipeID.data(indexPath));
		                    }
		                }
		            }
		        }
		        attachedObjects: [
		            ComponentDefinition {
		                id: recipePageDefinition
		                source: "recipe.qml"
		            },
		            ComponentDefinition {
		                id: addPageDefinition
		                source: "add.qml"
		            },
		            ComponentDefinition {
		                id: fileOpPageDefinition
		                source: "fileOp.qml"
		            }
		        ]
		        actions: [
		            ActionItem {
		                title: "AddItem"
		                //ActionBar.placement: ActionBarPlacement.OnBar
		                onTriggered: {
		                    var page = addPageDefinition.createObject();
		                    nav.push(page);
		                }
		            },
		            ActionItem {
		                title: "Save/Load Demo"
		                //ActionBar.placement: ActionBarPlacement.OnBar
		                onTriggered: {
		                    var page = fileOpPageDefinition.createObject();
		                    nav.push(page);
		                }
		            }
		        ]
		    }
		    onTopChanged: {
		        if (page == mainPage) {
		            recipeList.clearSelection();
		            TestObject.getFullList();
		        }
		    }
		    onPopTransitionEnded: {
		        page.destroy();
		    }
		}
    }
    Tab {
        title: "Inventory"
        NavigationPane {
            Page {
                titleBar: TitleBar {
                    title: "Inventory Page"
                }
                Container {
		            layout: StackLayout {}
		            ListView {
		                id: invList
		                objectName: "invList"
		                dataModel: invName
		                layout: StackListLayout {}
		                attachedObjects: [
		                    ArrayDataModel {
		                        id: invID
		                        objectName: "invID"
		                    },
		                    ArrayDataModel {
		                        id: invName
		                        objectName: "invName"
		                    }
		                ]
		                onTriggered: {
		                    toggleSelection(indexPath);
		                    
		                    //var page = recipePageDefinition.createObject();
		                    //nav.push(page);
		                }
		                onSelectionChanged: {
		                    if (selected) {
		                    //    TestObject.getRecipe(indexPath, recipeID.data(indexPath));
		                    }
		                }
		            }
		        }
            }
        }
    }
    Tab {
        title: "Shopping List"
        NavigationPane {
            Page {
                titleBar: TitleBar {
                    title: "Shopping List Page"
                }
                Container {
		            layout: StackLayout {}
		            ListView {
		                id: shopList
		                objectName: "shopList"
		                dataModel: shopName
		                layout: StackListLayout {}
		                attachedObjects: [
		                    ArrayDataModel {
		                        id: shopID
		                        objectName: "shopID"
		                    },
		                    ArrayDataModel {
		                        id: shopName
		                        objectName: "shopName"
		                    }
		                ]
		                onTriggered: {
		                    toggleSelection(indexPath);
		                    
		                    //var page = recipePageDefinition.createObject();
		                    //nav.push(page);
		                }
		                onSelectionChanged: {
		                    if (selected) {
		                    //    TestObject.getRecipe(indexPath, recipeID.data(indexPath));
		                    }
		                }
		            }
		        }
            }
        }
    }
}