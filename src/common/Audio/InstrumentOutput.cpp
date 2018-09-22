/**
 * Instrument output to jack capable
 */
#include <cmath>
#include <stdio.h>
#include <iostream>

#include "InstrumentOutput.h"


namespace Orza { namespace Steel { namespace Audio {

/**
 * Constructor
 */

InstrumentOutput::InstrumentOutput() {
}

//Fast sign
//@TODO move
int doublePi = (M_PI*M_PI);
const float B = 4.0f/M_PI;
const float C = -4.0f/doublePi;
const float P = 0.225f;

float fastSin( float x ){
	// restrict x so that -M_PI < x < M_PI
	x = fmod(x + M_PI, M_PI * 2) - M_PI;

	float y = B * x + C * x * std::abs(x);

	return P * (y * std::abs(y) - y) + y;
}


/**
 * Get output main method
 */

jack_default_audio_sample_t * InstrumentOutput::writeOutput(
	jack_port_t * port,
	jack_nframes_t nframes,
	jack_default_audio_sample_t srate,
	vector<float_t> freqs
) {
	//Get port buffer
	jack_default_audio_sample_t * out = (jack_default_audio_sample_t *) jack_port_get_buffer(port, nframes);


	//If note use srate math
	jack_default_audio_sample_t noteFrequency = 0.0;

	if( freqs.size() > 0 ) {
		noteFrequency = freqs[0] / srate;
	}


	float_t mpi = 2 * M_PI;

	//loop frames
	for( int i = 0; i < nframes; i ++ ) {

		//No notes
		if (noteFrequency == 0.0) {
			out[i] = 0.0;
			continue;
		}

		_ramp += noteFrequency;

		if (_ramp > 1.0) {
			_ramp -= 2.0;
		}

		out[i] = sin( mpi * _ramp );
		//out[i] = fastSign( mpi * _ramp ) * 0.1;

		//if (!(i % 7)) {
			//printf("RAMP %F", _ramp);
			//printf(", Freq %F", noteFrequency);
			//printf(", SIGNAL %F\n", sin(2*M_PI*_ramp));
		//}

	}

	return out;

};

} } }
