/**
 * Base module virtual
 */
#pragma once


namespace Orza { namespace Steel {

class Window;


using Orza::Steel::Window;


/**
 * Class
 */

class BaseModule {

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
