/**
 * Module
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <jack/jack.h>

#include <Audio/StringInstrument.h>
#include <Audio/InstrumentOutput.h>

#include <Module/BaseModule.h>

#include <Audio/Wave/BaseWave.h>
#include <Audio/Wave/NullWave.h>
#include <Audio/Wave/SineWave.h>
#include <Audio/Wave/TriangleWave.h>
#include <Audio/Wave/SquareWave.h>

#include "Bridge.h"
#include "Neck.h"


using std::map;
using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::InstrumentOutput;

using Orza::Steel::Audio::Wave::BaseWave;
using Orza::Steel::Audio::Wave::NullWave;


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


		/**
		 * Pedal stuff
		 */

		void setPedals();


	private:

		/**
		 * GUI / submod
		 */

		Bridge * _bridge;

		Neck * _neck;


		/**
		 * Audio
		 */

		StringInstrument * _instrument;

		InstrumentOutput * _outputter;


		/**
		 * Wave for output
		 */

		BaseWave * _wave;

		NullWave * _nullWave;


		map<uint8_t, float_t> getHandMap( vector<uint8_t> * bridged );


};

} } }
