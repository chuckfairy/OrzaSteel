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

	//Decay
	connect(
		_UI.decay_slider,
		SIGNAL( valueChanged(int) ),
		this,
		SLOT( handleDecayChange(int) )
	);

	//Sustain
	connect(
		_UI.sustain_slider,
		SIGNAL( valueChanged(int) ),
		this,
		SLOT( handleSustainChange(int) )
	);

	//Release
	connect(
		_UI.release_slider,
		SIGNAL( valueChanged(int) ),
		this,
		SLOT( handleReleaseChange(int) )
	);

}


void EnvelopeEditor::handleAttackChange(int value) {

	std::cout << "Attack Change " << value << " " << _UI.attack_slider->maximum() << "\n";
	float_t attack = ((float)value / (float)_UI.attack_slider->maximum()) * 5;
	_env->setAttack(attack);

	emitUpdate();

};

void EnvelopeEditor::handleDecayChange(int value) {

	std::cout << "Decay Change " << value << " " << _UI.decay_slider->maximum() << "\n";
	float_t decay = ((float)value / (float)_UI.decay_slider->maximum()) * 5;
	_env->setDecay(decay);

	emitUpdate();

};

void EnvelopeEditor::handleSustainChange(int value) {

	std::cout << "Sustain Change " << value << " " << _UI.sustain_slider->maximum() << "\n";
	float_t sustain = ((float)value / (float)_UI.sustain_slider->maximum());
	_env->setSustain(sustain);

	emitUpdate();

};

void EnvelopeEditor::handleReleaseChange(int value) {

	std::cout << "Release Change " << value << " " << _UI.release_slider->maximum() << "\n";
	float_t release = ((float)value / (float)_UI.release_slider->maximum()) * 5;
	_env->setRelease(release);

	emitUpdate();

};

void EnvelopeEditor::emitUpdate() {

	emit EnvelopeChange(_env);

};

} } }
