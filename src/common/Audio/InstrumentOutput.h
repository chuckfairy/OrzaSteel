/**
 * Instrument output to jack capable
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <jack/jack.h>
#include <jack/midiport.h>


using std::vector;


namespace Orza { namespace Steel { namespace Audio {


class InstrumentOutput {

	public:

		InstrumentOutput();


		/**
		 * Get output main method
		 */

		jack_default_audio_sample_t * writeOutput(
			jack_port_t * port,
			jack_nframes_t nframes,
			jack_default_audio_sample_t sample_rate,
			vector<float_t> freqs
		);


	private:

		/**
		 * Jack props
		 */

		jack_default_audio_sample_t _ramp = 0.0;

};

} } }
