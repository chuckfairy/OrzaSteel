/**
 * Pedal editor
 */
#include <Util/Vector.h>

#include "SoundEditor.h"

#include <Window.h>

#include <Instrument/Module.h>


using Orza::Steel::Instrument::Module;
using Orza::Steel::Window;

using Orza::Steel::Audio::Wave::BaseWave;
using Orza::Steel::Audio::Wave::NullWave;
using Orza::Steel::Audio::Wave::SineWave;
using Orza::Steel::Audio::Wave::SquareWave;
using Orza::Steel::Audio::Wave::TriangleWave;
using Orza::Steel::Audio::Wave::SawtoothWave;


namespace Orza { namespace Steel { namespace Settings {


SoundEditor::SoundEditor( Window * window ) :
    _win( window )
{

	//@TODO move
	Module * insta = (Module*) _win->getModules()[0];

	_env = insta->getEnvelope();

	_envelopeEditor = new EnvelopeEditor(_env);

	_UI.setupUi( this );

	_UI.contentLayout->addWidget(_envelopeEditor);

	buildWaveformCombo();

	connect(
		_UI.waveform_combo,
		SIGNAL( currentIndexChanged( int ) ),
		this,
		SLOT( handleWaveCombo(int) )
	);

};

void SoundEditor::handleWaveCombo(int index) {

	handleWaveChange(_waves[index]);

};

void SoundEditor::handleWaveChange( BaseWave * wave ) {

	//@TODO move
	Module * insta = (Module*) _win->getModules()[0];
	insta->setWave( wave );

};


void SoundEditor::buildWaveformCombo() {

	_waves.push_back(new SineWave);
	_waves.push_back(new SquareWave);
	_waves.push_back(new TriangleWave);
	_waves.push_back(new SawtoothWave);

	_UI.waveform_combo->addItem("Sine");
	_UI.waveform_combo->addItem("Square");
	_UI.waveform_combo->addItem("Triangle");
	_UI.waveform_combo->addItem("Sawtooth");

};

} } }
