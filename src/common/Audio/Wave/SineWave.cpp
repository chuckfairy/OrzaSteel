/**
 * Wavefrom base class
 */
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
	float_t volume
) {

	float noteFrequency = _freqs[ 0 ];


	//loop frames

	for( uint32_t i = 0; i < nframes; ++ i ) {

		_ramp += noteFrequency;

		if (_ramp > _threshold) {
			_ramp -= _delta;
		}

		output[i] = volume * sin( DOUBLE_PI * _ramp );

	}

};

} } } }
