import bb.cascades 1.0

Page {
    id: nfcsharePage
    
    property string original_text
    
	function message(text, formatted_text) {
	    console.log(text);
	    recipe.text = formatted_text;    
	    original_text = text;
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
                _nfcHandlerObject.parseText(original_text);
                nav.pop();
            }
        }
    ]
}