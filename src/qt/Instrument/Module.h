/**
 * Module
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <jack/jack.h>

#include <Audio/StringInstrument.h>
#include <Audio/InstrumentOutput.h>

#include <Module/BaseModule.h>

#include "Bridge.h"
#include "Neck.h"


using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::InstrumentOutput;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Main
 */

class Module : public BaseModule {

	public:

		Module( Window * );

		~Module() {};


		/**
		 * Set strings main
		 */

		void setStrings( vector<float_t> );


		/**
		 * Main jack stuff
		 */

		void process( jack_nframes_t );

        void handleKeyEvent( QKeyEvent * event );


	private:

		jack_port_t * _output_port;


		/**
		 * Audio
		 */

		StringInstrument * _instrument;

		InstrumentOutput * _outputter;

		/**
		 * GUI
		 */

		Bridge * _bridge;

		Neck * _neck;

};

} } }
