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

	map<uint8_t, float_t>::iterator it;

	for(it = _freqs.begin(); it != _freqs.end(); ++it) {

		//Get

		float_t noteFrequency = it->second;

		float_t ramp = _ramps[ it->first ];


		//Check threwshold from add

		ramp += noteFrequency;

		if( ramp > _threshold ) {

			ramp -= _delta;

		}


		//Set ramp for next time

		_ramps[ it->first ] = ramp;


		//Get sine signal

		float_t sig = sin( DOUBLE_PI * ramp );

		out += ( sig * (volPer * getVolumeFromEnvelope(env, it->first) ) );

		++_rampTimes[it->first];

	}

	return out;

};

} } } }
