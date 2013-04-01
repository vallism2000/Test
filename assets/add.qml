import bb.cascades 1.0

Page {
    id: addPage
    titleBar: TitleBar {
        title: "Add New Recipe"
    }
    Container {
        layout: StackLayout {}
        
        TextArea {
            id: addName
            objectName: "addName"
            hintText: "Recipe Name"
        }
        TextArea {
            id: addInfo
            objectName: "addInfo"
            hintText: "Recipe Information"
        }
        TextArea {
            id: addInst
            objectName: "addInst"
            hintText: "Recipe Instructions"
        }
        ScrollView {
            Container {
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
		        TextArea {
		        }
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