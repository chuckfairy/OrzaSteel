/**
 * string editor
 */
#include "EnvelopeEditor.h"


namespace Orza { namespace Steel { namespace Settings {

/**
 * Events
 */

const char * EnvelopeEditor::ENVELOPE_CHANGE = "ENV_CHANGE";



/**
 * Construct
 */

EnvelopeEditor::EnvelopeEditor() {

	_UI.setupUi( this );

	connect(
		_UI.attack_slider,
		SIGNAL( valueChanged(int) ),
		this,
		SLOT( handleAttackChange(int) )
	);

};


void EnvelopeEditor::handleAttackChange(int value) {

	_env->attack = value / _UI.attack_slider->maximum();

};

} } }
