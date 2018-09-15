/**
 * Module impl instrument
 */
#include "Module.h"

#include <Window.h>


using Orza::Steel::BaseModule;
using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Instrument {

Module::Module( Window * win ) :
	BaseModule( win ),
	_bridge( new Bridge )
{

	_window->getUI()->bridge->addWidget( _bridge );

};

} } }
