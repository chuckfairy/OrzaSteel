/**
 * String down
 */
#pragma once

#include <Util/Dispatcher.h>


namespace Orza { namespace Steel { namespace Instrument {

template <typename T, typename S>
class StringDownEvent : public Util::Event {

	public:

		StringDownEvent( T * t ) :
			_Handler( t )
		{};

		~StringDownEvent() {};

		void run( void * data ) {

			_Handler->handleStringDown( (S*) data );

		};


	private:

		T * _Handler;

};

} } }
