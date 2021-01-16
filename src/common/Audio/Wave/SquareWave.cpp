/**
 * Wavefrom base class
 */
#include "SquareWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t SquareWave::DOUBLE_PI = 2 * M_PI;


/**
 * Main signal math for chords
 * Square wave from a sine wave
 *
 * https://stackoverflow.com/questions/7400834/creating-a-triangle-wave-from-a-sine-wave-in-c
 *
 */

float_t SquareWave::getRampSignal( Envelope * env, float_t ramp ) {


	float_t sig = sin( DOUBLE_PI * ramp );

	return ( sig >= 0 )
		? _threshold
		: - _threshold;

};

} } } }
