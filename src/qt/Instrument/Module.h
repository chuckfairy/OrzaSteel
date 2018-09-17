/**
 * Module
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <Instrument/StringInstrument.h>

#include <Module/BaseModule.h>

#include "Bridge.h"
#include "Neck.h"

using std::map;
using std::vector;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;


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


	private:

		/**
		 * Audio
		 */

		StringInstrument * _instrument;


		/**
		 * GUI
		 */

		Bridge * _bridge;

		Neck * _neck;


		/**
		 * Processing
		 */

		map<uint8_t, float_t> getHand();

		vector<float_t> getFrequencies();

};

} } }
