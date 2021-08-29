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

EnvelopeEditor::EnvelopeEditor(Envelope * env)
{
	setup();
	setEnvelope(env);
}


/**
 * setter and setup UI
 */

Envelope * EnvelopeEditor::getEnvelope() {
	return _env;
};


void EnvelopeEditor::setEnvelope(Envelope * env) {
	_env = env;

	updateFromEnvelope();
};

void EnvelopeEditor::updateFromEnvelope() {

	//Attack
	float_t attack = (_env->getAttack() * (float)_UI.attack_slider->maximum()) / deltaValue;
	_UI.attack_slider->setTickInterval(floor(attack));

	float_t decay = (_env->getDecay() * (float)_UI.decay_slider->maximum()) / deltaValue;
	_UI.decay_slider->setTickInterval(floor(decay));

	//Sustain
	float_t sustain = (float)_env->getSustain() * _UI.sustain_slider->maximum();
	_UI.sustain_slider->setTickInterval(floor(sustain));

	float_t release = (_env->getRelease() * (float)_UI.release_slider->maximum()) / deltaValue;
	_UI.release_slider->setTickInterval(floor(release));

};


/**
 * Events
 */

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
	float_t attack = ((float)value / (float)_UI.attack_slider->maximum()) * deltaValue;
	_env->setAttack(attack);

	emitUpdate();

};

void EnvelopeEditor::handleDecayChange(int value) {

	std::cout << "Decay Change " << value << " " << _UI.decay_slider->maximum() << "\n";
	float_t decay = ((float)value / (float)_UI.decay_slider->maximum()) * deltaValue;
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
	float_t release = ((float)value / (float)_UI.release_slider->maximum()) * deltaValue;
	_env->setRelease(release);

	emitUpdate();

};

void EnvelopeEditor::emitUpdate() {

	emit EnvelopeChange(_env);

};

} } }
