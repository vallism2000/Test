/*
 * NFCHandler.cpp
 *
 */


#include "NFCHandler.hpp"
#include <QRegExp>
#include <QString>
#include <iostream>
#include <string>

#include "events/AddRecipeEvent.hpp"
#include "CoreEventBus.hpp"

NFCHandler* NFCHandler::nfch_instance;

NFCHandler::NFCHandler(){
		share_manager = new bb::system::NfcShareManager();

	    QObject::connect(share_manager, SIGNAL(shareModeChanged(bb::system::NfcShareMode::Type)), this, SLOT(shareModeChanged(bb::system::NfcShareMode::Type)));
	    QObject::connect(share_manager, SIGNAL(finished(bb::system::NfcShareSuccess::Type)), this, SLOT(finished(bb::system::NfcShareSuccess::Type)));
	    QObject::connect(share_manager, SIGNAL(error(bb::system::NfcShareError::Type)), this, SLOT(error(bb::system::NfcShareError::Type)));

	    QObject::connect( this, SIGNAL(setShareMode(bb::system::NfcShareMode::Type)), share_manager, SLOT(setShareMode(bb::system::NfcShareMode::Type)));
}

NFCHandler::~NFCHandler(){

}

void NFCHandler::disableSharing() {
    qDebug() << "sharing disabled" << endl;
    setSharingActive(false);
    emit setShareMode(bb::system::NfcShareMode::Disabled);
}

void NFCHandler::enableDataSharing() {
	setSharingActive(true);
	emit setShareMode(bb::system::NfcShareMode::Data);
}

bool NFCHandler::sharingActive() const {
	return sharing_active;
}

void NFCHandler::setSharingActive(bool sharingState) {
	if (sharing_active == sharingState){
		return;
	}
	sharing_active = sharingState;
	emit detectSharingActive();
}
void NFCHandler::shareModeChanged(bb::system::NfcShareMode::Type mode) {
    qDebug() << "shareModeChanged mode =" << mode << endl;
}

void NFCHandler::finished(bb::system::NfcShareSuccess::Type result) {
    qDebug() << "finished result code  =" << result << endl;
}

void NFCHandler::error(bb::system::NfcShareError::Type error) {
    qDebug() << "error =" << error << endl;
}



NFCHandler* NFCHandler::getInstance(){

	if(nfch_instance == NULL){
		nfch_instance = new NFCHandler();
	}
	return nfch_instance;
}

// This is a version of the NdefFactory::getTextFromTextRecordPayload method from NFCLiteTool (Apache License, Version 2.0)
QString NFCHandler::getText(const QByteArray &payload) {

	QString text;
	uchar_t statusByte = payload[0];
	bool isUtf16 = false;

	if ( statusByte & 0x80 ) { // bit 7 is UTF type ( 8 or 16 )
		isUtf16 = true;
	}
	int langLen = statusByte & 0x3F; // lower 6 bits is language length

	if (isUtf16) {
		text = QString(payload.mid(1+langLen).constData());
	} else {
		text = QString::fromUtf8(payload.mid(1+langLen).constData());
	}

	return text;
}

/* This takes the text recevied from nfc and puts it in a easily readable
 * format to display to the user.
 */
QString NFCHandler::FormatTextForPage(const QByteArray &payload) {
	QString text = getText(payload);
	std::string holder;

	QStringList list;
		QStringList ingList;
		list = text.split("}", QString::SkipEmptyParts);
		int rating;
		std::string name;
		std::string desc;
		std::string instructions;
		std::string ing_name;
		std::string amount;

		// Messy parsing that could be improved
		for(int i=0; i<list.length(); i++){

			QStringList looplist;
			looplist = list.at(i).split(":", QString::SkipEmptyParts);

			// Get rid of leading {
			QString type = looplist.at(0);
			type = type.remove(QChar('{'), Qt::CaseInsensitive).trimmed();

			if(type.toStdString() == "rating"){

				rating = looplist.at(1).toInt();
				std::cout << "rating: " << rating << std::endl;

			} else if(type.toStdString() == "name"){

				name = looplist.at(1).trimmed().toStdString();
				std::cout << "name " << name << std::endl;

			} else if(type.toStdString() == "desc"){

				desc = looplist.at(1).trimmed().toStdString();
				std::cout << "desc: " << desc << std::endl;

			} else if(type.toStdString() == "instructions"){

				instructions = looplist.at(1).trimmed().toStdString();
				std::cout << "instructions: " << instructions << std::endl;

			} else if(type.toStdString() == "ingredients"){
					ingList = looplist.at(1).split("]", QString::SkipEmptyParts);
			}

		}

		holder = name + "\n\n";
		holder += desc + "\n\n";
		holder += "Ingredients: \n";


	    for(int j=0; j<ingList.length(); j++){
	    	// Get rid of leading [
			QString ing_str = ingList.at(j);
			ing_str = ing_str.remove(QChar('['), Qt::CaseInsensitive).trimmed();

			QStringList tmp;
			tmp = parseIngredient(ing_str);
			ing_name = tmp.at(0).toStdString();
			amount = tmp.at(1).toStdString();
			holder += ing_name + "\t" + amount + "\n";
	    }

	    holder += "\nInstructions: \n" + instructions + "\n\n";
	    holder += "Rating: ";
	    holder += QString::number(rating).toStdString();

	return QString::fromStdString(holder);
}

void NFCHandler::parseText(QString text){

	std::cout << "Parsing..." << text.toStdString() << std::endl;

	QStringList list;
	QStringList ingList;
	list = text.split("}", QString::SkipEmptyParts);
	int rating;
	std::string name;
	std::string desc;
	std::string instructions;
	std::string ing_name;
	std::string amount;

	// Messy parsing that could be improved
	for(int i=0; i<list.length(); i++){

		QStringList looplist;
		looplist = list.at(i).split(":", QString::SkipEmptyParts);

		// Get rid of leading {
		QString type = looplist.at(0);
		type = type.remove(QChar('{'), Qt::CaseInsensitive).trimmed();

		if(type.toStdString() == "rating"){

			rating = looplist.at(1).toInt();
			std::cout << "rating: " << rating << std::endl;

		} else if(type.toStdString() == "name"){

			name = looplist.at(1).trimmed().toStdString();
			std::cout << "name " << name << std::endl;

		} else if(type.toStdString() == "desc"){

			desc = looplist.at(1).trimmed().toStdString();
			std::cout << "desc: " << desc << std::endl;

		} else if(type.toStdString() == "instructions"){

			instructions = looplist.at(1).trimmed().toStdString();
			std::cout << "instructions: " << instructions << std::endl;

		} else if(type.toStdString() == "ingredients"){
				ingList = looplist.at(1).split("]", QString::SkipEmptyParts);
		}

	}

	// Set up AddRecipeEvent, then loop to add the ingredients
    AddRecipeEvent* ae = new AddRecipeEvent(rating, name, desc, instructions);

    for(int j=0; j<ingList.length(); j++){
    	// Get rid of leading [
		QString ing_str = ingList.at(j);
		ing_str = ing_str.remove(QChar('['), Qt::CaseInsensitive).trimmed();

		QStringList tmp;
		tmp = parseIngredient(ing_str);
		ing_name = tmp.at(0).toStdString();
		amount = tmp.at(1).toStdString();

		std::cout << "ingredient: " << ing_name << "  amount: " << amount << std::endl;
		ae->AddIngredient(ing_name, amount);

    }

    // Fire add event
    CoreEventBus::FireEvent(ae);


}

QStringList NFCHandler::parseIngredient(QString ing){
	QStringList list;
	QStringList result;
	list = ing.split(")", QString::SkipEmptyParts);

	for(int i=0; i<list.length(); i++){
			QStringList looplist;
			looplist = list.at(i).split(",", QString::SkipEmptyParts);

			// Get rid of leading (
			QString type = looplist.at(0);
			type = type.remove(QChar('('), Qt::CaseInsensitive).trimmed();


			if(type.toStdString() == "name"){

				result.insert(0, looplist.at(1).trimmed());

			} else if(type.toStdString() == "amount"){
				result.insert(1,looplist.at(1).trimmed());

			}

		}

	return result;

}

void NFCHandler::dataShareContentChanged(QString message) {
    // Not sure if I ever call this function
	bb::system::NfcShareDataContent request;
    QByteArray data(message.toUtf8());
    request.setMimeType("text/plain");
    request.setData(data);
    bb::system::NfcShareSetContentError::Type rc = share_manager->setShareContent(request);
}

bb::system::NfcShareManager* NFCHandler::getShareManager(){
	return share_manager;
}
