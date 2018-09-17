/**
 * Module impl instrument
 */
#include "Module.h"

#include <Window.h>


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
	_instrument( new StringInstrument )
{

	setStrings( StringInstrument::TYPE_DEFAULT );

	_window->getUI()->bridge->addWidget( _bridge );

};


/**
 * Jack processing
 */

void Module::process( jack_nframes_t nframe ) {



};


/**
 * Set strings func for setting
 */

void Module::setStrings( vector<float_t> freqs ) {

	_instrument->setStrings( freqs );

	_bridge->setNumStrings( _instrument->getNumStrings() );

};

} } }
