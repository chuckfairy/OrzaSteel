/**
 * Instrument output to jack capable
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <jack/jack.h>
#include <jack/midiport.h>

#include <Instrument/BaseInstrument.h>


using std::vector;


namespace Orza { namespace Steel { namespace Audio {


class InstrumentOutput {

	public:

		InstrumentOutput( BaseInstrument * );


		/**
		 * Get output main method
		 */

		jack_default_audio_sample_t * writeOutput(
			jack_port_t * port,
			jack_nframes_t nframes,
			vector<float_t> freqs = 0
		);


	private:

		/**
		 * Main instrument
		 */

		BaseInstrument * _instrument;


		/**
		 * Notes to know when to stop frequencies and such
		 */

		vector<float_t> _heldNotes;


		/**
		 * Jack props
		 */

		jack_default_audio_sample_t _srate;

		jack_default_audio_sample_t _ramp = 0.0;

};

} } }
