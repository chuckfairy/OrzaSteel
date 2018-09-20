/**
 * Module impl instrument
 */
#include "Module.h"

#include <cmath>
#include <cstdint>

#include <map>

#include <Window.h>

#include <Jack/PatchbayEffects.h>


using std::map;
using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Construct
 */

Module::Module( Window * win ) :
	BaseModule( win ),
	_bridge( new Bridge ),
	_instrument( new StringInstrument ),
	_outputter( new InstrumentOutput )
{

	setStrings( StringInstrument::TYPE_COUNTRY_NECK );

	_window->getUI()->bridge->addWidget( _bridge );

};


/**
 * Jack processing
 */

void Module::process( jack_nframes_t nframes ) {

	//Get frequencies

	vector<uint8_t> * hand = _bridge->getHand();

	vector<float_t> freqs = _instrument->getPitches( *hand );


	//Output

	_outputter->writeOutput(
		_window->getServer()->getPatchbay()->getEffects()->getInputPortRight(),
		nframes,
		freqs
	);

	_outputter->writeOutput(
		_window->getServer()->getPatchbay()->getEffects()->getInputPortLeft(),
		nframes,
		freqs
	);

};


/**
 * Set strings func for setting
 */

void Module::setStrings( vector<float_t> freqs ) {

	_instrument->setStrings( freqs );

	_bridge->setNumStrings( _instrument->getNumStrings() );

};

} } }
