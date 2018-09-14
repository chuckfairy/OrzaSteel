/**
 * Instrument output to jack capable
 */
#pragma once

#include <jack/jack.h>
#include <jack/midiport.h>

#include <Instrument/BaseInstrument.h>


namespace Orza { namespace Steel { namespace Audio {


class InstrumentOutput {

	public:

		InstrumentOutput( BaseInstrument * );


		/**
		 * Get output main method
		 */

		jack_default_audio_sample_t * getOutput( jack_nframes_t nframes );


	private:

		/**
		 * Main instrument
		 */

		BaseInstrument * _instrument;


		/**
		 * Notes to know when to stop frequencies and such
		 */

		vector<float_t> _heldNotes;

};

} } }
