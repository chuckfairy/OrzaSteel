/**
 * Instrument output to jack capable
 */
#pragma once

#include "InstrumentOutput.h"


namespace Orza { namespace Steel { namespace Audio {

/**
 * Constructor
 */

InstrumentOutput::InstrumentOutput( BaseInstrument * inst ) :
	_instrument( inst )
{
}


/**
 * Get output main method
 */

jack_default_audio_sample_t * InstrumentOutput::writeOutput(
	jack_port_t * port,
	jack_nframes_t nframes,
	vector<float_t> freqs = 0
) {

	//resetting state
	_ramp = 0.0;

	//Get port buffer
	jack_default_audio_sample_t * out;
	out = (jack_default_audio_sample_t *) jack_port_get_buffer(port, nframes);


	//If note use srate math
	jack_default_audio_sample_t noteFrequency = 0.0;

	if( freqs.size() > 0 ) {
		noteFrequency = freqs[0] / _srate;
	}


	//loop frames
	for( int i = 0; i < nframes; ++i ) {

		//No notes
		if (noteFrequency == 0.0) {
			out[i] = 0.0;
			continue;
		}

		ramp += note_frqs[note];
		ramp = (ramp > 1.0) ? ramp - 2.0 : ramp;

		out[i] = note_on*sin(2*M_PI*ramp);

	}

	return out;

};

} } }
