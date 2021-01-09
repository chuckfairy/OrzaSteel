/**
 * Wavefrom base class
 */
#include "TriangleWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t TriangleWave::DOUBLE_PI = 2 * M_PI;


/**
 * Main signal math for chords
 * triangle wave from a sine wave
 *
 * https://stackoverflow.com/questions/7400834/creating-a-triangle-wave-from-a-sine-wave-in-c
 *
 */

float_t TriangleWave::getRampSignal( Envelope * env, float_t volume ) {

	float_t out = 0.0;

	int freqSize = _freqs.size();

	float_t volPer = freqSize == 1
		? volume
		: (volume / (float_t) _freqs.size());

	float_t deltaVol = volPer * 1;

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


		float_t sig = ( ( 2 * deltaVol ) / M_PI ) * asin( sin( DOUBLE_PI * ramp ) );


		//get what direction from old

		out += sig;

	}

	return out;

};

} } } }
