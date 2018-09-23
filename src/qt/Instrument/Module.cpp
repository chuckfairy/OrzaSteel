/**
 * Module impl instrument
 */
#include "Module.h"

#include <cmath>
#include <cstdint>
#include <sstream>

#include <map>

#include <Window.h>

#include <Jack/PatchbayEffects.h>


using std::map;
using std::stringstream;
using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;

using Orza::Steel::Audio::Wave::BaseWave;
using Orza::Steel::Audio::Wave::NullWave;
using Orza::Steel::Audio::Wave::SineWave;



namespace Orza { namespace Steel { namespace Instrument {

/**
 * Construct
 */

Module::Module( Window * win ) :
	BaseModule( win ),
	_bridge( new Bridge ),
	_instrument( new StringInstrument ),
	_outputter( new InstrumentOutput ),
	_wave( new SineWave ),
	_nullWave( new NullWave )
{

	setStrings( StringInstrument::TYPE_COUNTRY_NECK );

	_window->getUI()->bridge->addWidget( _bridge );

	//_output_port = jack_port_register(
		//_window->getServer()->getJackClient(),
		//"orzasteel-output",
		//JACK_DEFAULT_AUDIO_TYPE,
		//JackPortIsOutput,
		//0
	//);

};


/**
 * Jack processing
 */

void Module::process( jack_nframes_t nframes ) {

	//Get frequencies

	vector<uint8_t> * hand = _bridge->getHand();

	vector<float_t> freqs = _instrument->getPitches( *hand );


	//Check wave changes

	if( _bridge->hasChange() ) {

		//Wave setup

		_wave->setWave(
			freqs,
			_window->getServer()->getSampleRate()
		);

		_bridge->setChanged();

	}


	//Null wave if 0 freqs

	BaseWave * waveUse = (freqs.size() == 0)
		? _nullWave
		: _wave;


	//Output

	_outputter->writeOutputWave(
		_window->getServer()->getPatchbay()->getEffects()->getInputPortLeft(),
		waveUse,
		nframes
	);

	//_outputter->writeOutput(
		//_window->getServer()->getPatchbay()->getEffects()->getInputPortLeft(),
		//nframes,
		//freqs
	//);

};


/**
 * Key event handling
 */

void Module::handleKeyEvent( QKeyEvent * event ) {

	std::cout << "Key Type : " << (event->type() == QEvent::KeyPress) << "\n";
	std::cout << "Key Btn : " << event->text().toUtf8().data() << "\n";

	//@TODO configs
	switch( event->key() ) {
		case Qt::Key_1:
		case Qt::Key_2:
		case Qt::Key_3:
		case Qt::Key_4:
		case Qt::Key_5:
		case Qt::Key_6:
			stringstream strValue;
			strValue << event->text().toUtf8().data();

			unsigned int index;
			strValue >> index;

			( event->type() == QEvent::KeyPress )
				?  _bridge->setStringDown( index )
				: _bridge->setStringUp( index );
			break;
	}

};


/**
 * Set strings func for setting
 */

void Module::setStrings( vector<float_t> freqs ) {

	_instrument->setStrings( freqs );

	_bridge->setNumStrings( _instrument->getNumStrings() );

};

} } }
