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

float_t SineWave::getRampSignal( Envelope * env, float_t ramp ) {

	return sin( DOUBLE_PI * ramp );

};

} } } }
