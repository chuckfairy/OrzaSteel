/**
 * Wavefrom base class
 */
#pragma once

#include "SineWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t SineWave::DOUBLE_PI = 2 * M_PI;


/**
 * Main output
 */

void SineWave::setOutputForTime(
	float * output,
	uint32_t nframes,
	float_t volume = 1.0
) {

	float noteFrequency = _freqs[ 0 ];


	//loop frames

	for( int i = 0; i < nframes; ++ i ) {

		_ramp += noteFrequency;

		if (_ramp > _threshold) {
			_ramp -= _delta;
		}

		output[i] = volume * sin( mpi * _ramp );

	}

};

} } } }
