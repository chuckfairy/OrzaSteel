/**
 * string editor
 */
#include <iostream>

#include "EnvelopeEditor.h"


namespace Orza { namespace Steel { namespace Settings {

/**
 * Events
 */

const char * EnvelopeEditor::ENVELOPE_CHANGE = "ENV_CHANGE";



/**
 * Construct
 */

EnvelopeEditor::EnvelopeEditor(Envelope * env) :
	_env(env)
{
	setup();
}


void EnvelopeEditor::setup() {

	_UI.setupUi( this );

	connect(
		_UI.attack_slider,
		SIGNAL( valueChanged(int) ),
		this,
		SLOT( handleAttackChange(int) )
	);

}


void EnvelopeEditor::handleAttackChange(int value) {

	std::cout << "Attack Change " << value << " " << _UI.attack_slider->maximum() << "\n";
	_env->attack = ((float)value / (float)_UI.attack_slider->maximum()) * 5;
	emitUpdate();

};

void EnvelopeEditor::emitUpdate() {

	emit EnvelopeChange(_env);

};


} } }
