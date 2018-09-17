/**
 * String up
 * Move to common lib
 *
 */
#pragma once

#include <jack/jack.h>

#include <Util/Dispatcher.h>


namespace Orza { namespace Steel { namespace Event {


template <typename T>
class JackProcess : public Util::Event {

	public:

		JackProcess( T * t ) :
			_Handler( t )
		{};

		~JackProcess() {};

		void run( void * data ) {

			_Handler->process( (jack_nframes_t) (uintptr_t) data );

		};


	private:

		T * _Handler;

};

} } }

