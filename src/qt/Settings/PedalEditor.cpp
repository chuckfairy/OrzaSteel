/**
 * Pedal editor
 */
#include "PedalEditor.h"


namespace Orza { namespace Steel { namespace Settings {

PedalEditor::PedalEditor() {

	_UI.setupUi( this );

	connect(
		_UI.add_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handleAddClick() )
	);

};

void PedalEditor::handleAddClick() {

    PedalEditArea * area = new PedalEditArea();

    _UI.pedal_content->addWidget( area );

    _areas.push_back( area );

};

/**
 * Build from
 */

void PedalEditor::buildFrom( vector<Pedal*> pedals ) {

    for( int i = 0; i < pedals.size(); ++ i ) {

        Pedal * pedal = pedals[ i ];
        PedalEditArea * area = new PedalEditArea();
        _UI.pedal_content->addWidget( area );

        area->setLabel( pedal->label );
        area->setModifier( pedal->steps );
        area->setStrings( pedal->strings );

        _areas.push_back( area );

    }

};

} } }
