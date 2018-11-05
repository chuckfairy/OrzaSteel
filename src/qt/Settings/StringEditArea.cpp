/**
 * string editor
 */
#include <Midi/Note.h>

#include <Widget/MidiNoteDropdown.h>

#include "StringEditArea.h"

#include "Events/UpdateEvent.h"


namespace Orza { namespace Steel { namespace Settings {

/**
 * Events
 */

const char * StringEditArea::NODE_UPDATE_EVENT = "UP";


/**
 * Construct
 */

StringEditArea::StringEditArea() {

	_UI.setupUi( this );

	//setViewButton( _UI.view_btn, _UI.body );

	setDeleteButton( _UI.delete_btn );


    _UI.note_input->setText( "0" );

	connect(
		_UI.note_input,
		SIGNAL( textChanged(const QString &) ),
		this,
		SLOT( sendUpdate() )
	);

    Orza::Widget::MidiNoteDropdown::buildOn( _UI.comboBox );

};


/**
 * Value based
 */

float StringEditArea::getStringNote() {

    //return _UI.comboBox->currentIndex() + Orza::Midi::NOTE_MIN;

    return _UI.note_input->text().toDouble();

};

void StringEditArea::setStringNote( float id ) {

    char buffer[64];
    int ret = snprintf(buffer, sizeof buffer, "%f", id);

    _UI.note_input->setText( buffer );

    //_UI.comboBox->setCurrentIndex( id - Orza::Midi::NOTE_MAX );

}

void StringEditArea::sendUpdate() {

    dispatch( StringEditArea::NODE_UPDATE_EVENT, this );

};

} } }
