/**
 * Jack redirector, will take input to output
 * for single interface view
 *
 */
#pragma once

#include <Audio/Plugin.h>
#include <Util/Dispatcher.h>


namespace Orza { namespace Steel { namespace Settings {

template <class Interface, class Cast>
class UpdateEvent : public Util::Event {

	public:

		explicit UpdateEvent( Interface * i ) : _Host( i ) {

		};


		void run( void * data ) {

			_Host->handleNodeUpdate( (Cast*) data );

		};


	private:

		Interface * _Host;

};

} } }
