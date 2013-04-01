import bb.cascades 1.0

Page {
    id: nfcsharePage
	function message(text) {
	    console.log(text);
	    recipe.text = text;    
	}
    titleBar: TitleBar {
    title: "Received Recipe via NFC"
    }
    content: Container {
	
	    TextArea {
	        id: recipe
	        text: qsTr("")
	        editable: false
	    }
    
    }
    
    actions: [
        ActionItem {
            id: share
            title: "Add to Recipes"
            imageSource: "asset:///ic_add.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            
            onTriggered: {
                console.log("Should parse the text add the recipe");
                _nfcHandlerObject.parseText(recipe.text);
                nav.pop();
            }
        }
    ]
}