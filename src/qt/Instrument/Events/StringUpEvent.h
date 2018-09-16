/**
 * String up
 */
#pragma once

#include <Util/Dispatcher.h>


namespace Orza { namespace Steel { namespace Instrument {

template <typename T, typename S>
class StringUpEvent : public Util::Event {

	public:

		StringUpEvent( T * t ) :
			_Handler( t )
		{};

		~StringUpEvent() {};

		void run( void * data ) {

			_Handler->handleStringUp( (S*) data );

		};


	private:

		T * _Handler;

};

} } }
