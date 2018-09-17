/**
 * Base module virtual
 */
#pragma once

#include <jack/jack.h>
#include <jack/midiport.h>


namespace Orza { namespace Steel {

class Window;


using Orza::Steel::Window;


/**
 * Class
 */

class BaseModule {

	public:

		/**
		 * Main processor virtual
		 */

		virtual void process( jack_nframes_t nframe ) {};


	protected:

		BaseModule( Window * win ) :
			_window( win )
		{
		};

		~BaseModule() {};


		/**
		 * Props
		 */

		Window * _window;

};

} }
