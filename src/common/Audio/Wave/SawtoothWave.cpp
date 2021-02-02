/**
 * Wavefrom base class
 */
#include <Util/Vector.h>

#include "SawtoothWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t SawtoothWave::DOUBLE_PI = 2 * M_PI;


/**
 * Construct
 */

SawtoothWave::SawtoothWave() {

	type = "sawtooth";

}


/**
 * Main signal math for chords
 *
 * https://en.wikipedia.org/wiki/Sawtooth_wave
 */

float_t SawtoothWave::getRampSignal( Envelope * env, float_t ramp ) {

	return ( 2 / M_PI ) * atan( tan( M_PI_2 - ramp ) );

};

} } } }
