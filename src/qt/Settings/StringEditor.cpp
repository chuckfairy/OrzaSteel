/**
 * string editor
 */
#include "StringEditor.h"


namespace Orza { namespace Steel { namespace Settings {

StringEditor::StringEditor() {

	_UI.setupUi( this );

	connect(
		_UI.add_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handleAddClick() )
	);

};


void StringEditor::handleAddClick() {

    StringEditArea * area = new StringEditArea();

    _UI.strings_content->addWidget( area );

    _areas.push_back( area );

};

} } }
