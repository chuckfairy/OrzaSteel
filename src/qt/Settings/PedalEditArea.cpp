/**
 * string editor
 */
#include <Midi/Note.h>

#include "PedalEditArea.h"


namespace Orza { namespace Steel { namespace Settings {

PedalEditArea::PedalEditArea() {

	_UI.setupUi( this );


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

} } }
