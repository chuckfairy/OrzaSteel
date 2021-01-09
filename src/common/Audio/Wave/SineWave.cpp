/**
 * Wavefrom base class
 */
#include <Util/Vector.h>

#include "SineWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t SineWave::DOUBLE_PI = 2 * M_PI;


/**
 * Main signal math for chords
 */

float_t SineWave::getRampSignal( Envelope * env, float_t volume ) {

	float_t out = 0.0;

	int freqSize = _freqs.size();

	float_t volPer = freqSize == 1
		? volume
		: (volume / (float_t) _freqs.size());

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

		out += ( sig * (volPer * getVolumeFromEnvelope(env, noteFrequency) ) );

		++_rampTimes[noteFrequency];

	}

	return out;

};

} } } }
