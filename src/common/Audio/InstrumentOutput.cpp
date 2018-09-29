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
 * Output wave
 */

void InstrumentOutput::writeOutputWave(
	jack_port_t * port,
	Wave::BaseWave * wave,
	jack_nframes_t nframes,
	float_t volume
) {

	jack_default_audio_sample_t * out = (jack_default_audio_sample_t *) jack_port_get_buffer(port, nframes);

	wave->setOutputForTime(
		out,
		nframes,
		volume
	);

};

} } }
