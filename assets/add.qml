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
		            objectName: "ing11"
		            hintText: "Ingredient 1"
		        }
		        TextArea {
		            objectName: "ing12"
		            hintText: "Amount of Ingredient 1"
		        }
		        TextArea {
		            objectName: "ing21"
		            hintText: "Ingredient 2"
		        }
		        TextArea {
		            objectName: "ing22"
		            hintText: "Amount of Ingredient 2"
		        }
		        TextArea {
		            objectName: "ing31"
		            hintText: "Ingredient 3"
		        }
		        TextArea {
		            objectName: "ing32"
		            hintText: "Amount of Ingredient 3"
		        }
		        TextArea {
		            objectName: "ing41"
		            hintText: "Ingredient 4"
		        }
		        TextArea {
		            objectName: "ing42"
		            hintText: "Amount of Ingredient 4"
		        }
		        TextArea {
		            objectName: "ing51"
		            hintText: "Ingredient 5"
		        }
		        TextArea {
		            objectName: "ing52"
		            hintText: "Amount of Ingredient 5"
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