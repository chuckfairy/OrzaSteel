/**
 * Wavefrom base class
 */
#include "NullWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

/**
 * Null just 0
 */

void NullWave::setOutputForTime(
	float * output,
	uint32_t nframes,
	float_t volume
) {

	//loop frames
	for( uint32_t i = 0; i < nframes; ++i ) {

		output[i] = 0.0;

	}

};

} } } }
