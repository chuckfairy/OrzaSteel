/**
 * string editor
 */
#include <Widget/MidiNoteDropdown.h>

#include "StringEditArea.h"


namespace Orza { namespace Steel { namespace Settings {

StringEditArea::StringEditArea() {

	_UI.setupUi( this );

    Orza::Widget::MidiNoteDropdown::buildOn( _UI.comboBox );

};

} } }

