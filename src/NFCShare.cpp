/*
 * NFCShare.cpp
 *
 */
#include "NFCShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include "drinkObjects/DrinkRecipe.hpp"
#include "drinkObjects/DrinkIngredient.hpp"
#include "NFCHandler.hpp"
#include <iostream>


NFCShare::NFCShare(){
	share_data = bb::system::NfcShareDataContent();
	share_manager = NFCHandler::getInstance()->getShareManager();
}

NFCShare::~NFCShare(){

}

void NFCShare::share(std::string data){
	// TODO: add the NFC calls to send the data to the other phone, send a ShareResponseEvent

	QString text = QString::fromStdString(data);
	QByteArray array_data = QByteArray();
	array_data.insert(0, text);
	share_data.setMimeType("text/plain");
	share_data.setData(array_data);
	share_manager->setShareMode(bb::system::NfcShareMode::Data);
	share_manager->setShareContent(share_data);


// Can't test invoke NFC on the simulator
/* QByteArray data_array = QByteArray();
 data_array.insert(0, QString::fromStdString(data) );
	m_Invocation = bb::cascades::Invocation::create(
			  bb::cascades::InvokeQuery::create()
			   .parent(this)
			   .mimeType("text/plain")
			   //.mimeType("application/drinkitapp")
			   .data(data_array)
			   //.invokeTargetId("sys.NFCViewer")
		);
	QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));
*/


}

std::string NFCShare::recipeToString(DrinkRecipe *r){
	/* Form for string should be:
	 * "{rating:#} {name: Recipe name} {desc: Description} {instructions: instructions} {ingredients: [(name, name1) (amount, amount1)] ... }
	 */

	std::string recipe_string;
	QString tmpstr = QString::number(r->GetRating());
	recipe_string.append("{rating: " + tmpstr.toStdString() + "} {name: " + r->GetName() + "} {desc: " + r->GetDesc() + "} ");
    recipe_string.append("{instructions: " + r->GetInstructions() + "} {ingredients: ");

    std::cout << recipe_string << std::endl;

    // loop to add ingredients
    int ing_amount = r->GetNumIngredients();
    for (int i = 0; i<ing_amount; i++){
        std::string iname = r->GetIngredient(i).GetName();
        std::string iamount = r->GetIngredientAmount(i);

        recipe_string.append("[(name, " + iname + ") (amount, " + iamount + ")] ");
    }

    recipe_string += "}";

    std::cout << recipe_string << std::endl;

	return recipe_string;
}

void NFCShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}

void NFCShare::clearShare(){
	share_manager->reset();
}
