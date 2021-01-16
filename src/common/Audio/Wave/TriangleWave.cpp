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
 * https://en.wikipedia.org/wiki/Triangle_wave
 *
 */

float_t TriangleWave::getRampSignal( Envelope * env, float_t ramp ) {


	return ( ( 2 * 1 ) / M_PI ) * asin( sin( DOUBLE_PI * ramp ) );

};

} } } }
