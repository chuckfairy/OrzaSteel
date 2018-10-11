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

#include <Audio/Pedal.h>

#include <Module/BaseModule.h>

#include <Audio/Wave/BaseWave.h>
#include <Audio/Wave/NullWave.h>
#include <Audio/Wave/SineWave.h>
#include <Audio/Wave/TriangleWave.h>
#include <Audio/Wave/SquareWave.h>

#include "Bridge.h"
#include "Neck.h"
#include "PedalWrap.h"
#include "PedalWrap.h"


using std::map;
using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::InstrumentOutput;
using Orza::Steel::Audio::Pedal;

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

		void handleResize( QResizeEvent * event );


		/**
		 * Pedal stuff
		 */

		void setPedals( vector<Pedal*> * );


	private:

		/**
		 * GUI / submod
		 */

		Bridge * _bridge;

		Neck * _neck;

		PedalWrap * _pedalWrap;

		vector<Pedal*> * _pedals;


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


		/**
		 * Internals
		 */

		bool HAS_CHANGE = false;

		map<uint8_t, float_t> getHandMap( vector<uint8_t> * bridged );

		void processPedals( char keyPressed, bool active );


};

} } }
