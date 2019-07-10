/**
 * string editor
 */
#include <string>

#include <Midi/Note.h>

#include <Util/Letters.h>

#include "PedalEditArea.h"


using std::string;


namespace Orza { namespace Steel { namespace Settings {

/**
 * Events
 */

const char * PedalEditArea::NODE_UPDATE_EVENT = "UP";


/**
 * Construct
 */


PedalEditArea::PedalEditArea() {

	_UI.setupUi( this );

	setDeleteButton( _UI.delete_btn );

	connect(
		_UI.label_edit,
		SIGNAL( textChanged(const QString &) ),
		this,
		SLOT( sendUpdate() )
	);

	connect(
		_UI.modifier_dropdown,
		SIGNAL( currentIndexChanged(int) ),
		this,
		SLOT( sendUpdate() )
	);

	connect(
		_UI.string_dropdown,
		SIGNAL( currentIndexChanged(int) ),
		this,
		SLOT( sendUpdate() )
	);

	connect(
		_UI.control_dropdown,
		SIGNAL( currentIndexChanged(int) ),
		this,
		SLOT( sendUpdate() )
	);


	setupKeySelect();


	//@TODO string updater
	_UI.modifier_dropdown->addItem( "-12" );
	_UI.modifier_dropdown->addItem( "-11" );
	_UI.modifier_dropdown->addItem( "-10" );
	_UI.modifier_dropdown->addItem( "-9" );
	_UI.modifier_dropdown->addItem( "-8" );
	_UI.modifier_dropdown->addItem( "-7" );
	_UI.modifier_dropdown->addItem( "-6" );
	_UI.modifier_dropdown->addItem( "-5" );
	_UI.modifier_dropdown->addItem( "-4" );
	_UI.modifier_dropdown->addItem( "-3" );
	_UI.modifier_dropdown->addItem( "-2" );
	_UI.modifier_dropdown->addItem( "-1" );
	_UI.modifier_dropdown->addItem( "0" );
	_UI.modifier_dropdown->addItem( "1" );
	_UI.modifier_dropdown->addItem( "2" );
	_UI.modifier_dropdown->addItem( "3" );
	_UI.modifier_dropdown->addItem( "4" );
	_UI.modifier_dropdown->addItem( "5" );
	_UI.modifier_dropdown->addItem( "6" );
	_UI.modifier_dropdown->addItem( "7" );
	_UI.modifier_dropdown->addItem( "8" );
	_UI.modifier_dropdown->addItem( "9" );
	_UI.modifier_dropdown->addItem( "10" );
	_UI.modifier_dropdown->addItem( "11" );
	_UI.modifier_dropdown->addItem( "12" );

	_UI.string_dropdown->addItem( "1" );
	_UI.string_dropdown->addItem( "2" );
	_UI.string_dropdown->addItem( "3" );
	_UI.string_dropdown->addItem( "4" );
	_UI.string_dropdown->addItem( "5" );
	_UI.string_dropdown->addItem( "6" );
	_UI.string_dropdown->addItem( "7" );
	_UI.string_dropdown->addItem( "8" );
	_UI.string_dropdown->addItem( "9" );
	_UI.string_dropdown->addItem( "10" );

};


/**
 * Value based
 */

void PedalEditArea::setLabel( const char * label ) {

	_UI.label_edit->setText( label );

};

void PedalEditArea::setModifier( int mod ) {

	_UI.modifier_dropdown->setCurrentIndex( mod + 12 );

};

void PedalEditArea::setStrings( vector<uint8_t> strings ) {

	_UI.string_dropdown->setCurrentIndex( strings[ 0 ] );

};


/**
 * Getters
 */

Pedal * PedalEditArea::getAsPedal() {

	_ped.label = _UI.label_edit->text().toStdString();
	_ped.steps = _UI.modifier_dropdown->currentText().toInt();
	_ped.strings = { (uint8_t) _UI.string_dropdown->currentText().toInt() };
	_ped.key = _UI.label_edit->text().toStdString().c_str()[0];

	return &_ped;

};


/**
 * Send update
 */

void PedalEditArea::sendUpdate() {

	dispatch( PedalEditArea::NODE_UPDATE_EVENT, this );

};


/**
 * Control key
 */

void PedalEditArea::setupKeySelect() {

	for(int i = 0; i < 26; ++ i) {

		char key = Orza::Letters::ALPHABET[i];
		string sym(1, key);
		_UI.control_dropdown->addItem( sym.c_str() );

	}

};

void PedalEditArea::setControlKey( char key ) {

	int index = 0;

	for(int i = 0; i < 26; ++ i) {

		if(key == Orza::Letters::ALPHABET[i]) {
			index = i;
		}
	}

	_UI.control_dropdown->setCurrentIndex(index);

};

} } }
