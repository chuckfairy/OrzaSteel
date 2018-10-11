/**
 * Base module virtual
 */
#pragma once

#include <jack/jack.h>
#include <jack/midiport.h>

#include <QKeyEvent>


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

		virtual void handleKeyEvent( QKeyEvent * event ) {};

		virtual void handleResize( QResizeEvent * event ) {};


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
