/**
 * Instrument output to jack capable
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <jack/jack.h>
#include <jack/midiport.h>

#include "Wave/BaseWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio {


class InstrumentOutput {

	public:

		InstrumentOutput();


		/**
		 * Get output main method
		 */

		void writeOutputWave(
			jack_port_t * port,
			Wave::BaseWave * wave,
			jack_nframes_t nframes,
			float_t volume = 1.0
		);


	private:

		/**
		 * Jack props
		 */

		jack_default_audio_sample_t _ramp = 0.0;

};

} } }
