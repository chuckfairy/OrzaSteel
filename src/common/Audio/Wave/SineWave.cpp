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

	//loop frames

	for( uint32_t i = 0; i < nframes; ++ i ) {

		output[i] = volume * getRampSignal( volume );

	}

};


/**
 * Main signal math for chords
 */

float_t SineWave::getRampSignal( int volume ) {

	float_t out = 0.0;

	int freqSize = _freqs.size();

	float_t volPer = freqSize == 1
		? volume
		: ((volume / _freqs.size()) + .25);

	for( int i = 0; i < _freqs.size(); ++ i ) {

		//Get

		float_t noteFrequency = _freqs[ i ];

		float_t ramp = _ramps[ i ];


		//Check threwshold from add

		ramp += noteFrequency;

		if( ramp > _threshold ) {

			ramp -= _delta;

		}


		//Set ramp for next time

		_ramps[ i ] = ramp;


		//Get sine signal

		float_t sig = sin( DOUBLE_PI * ramp );

		out += ( sig * volPer );

	}

	return out;

};

} } } }
