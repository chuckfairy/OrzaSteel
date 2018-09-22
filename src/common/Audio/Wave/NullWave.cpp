/**
 * Wavefrom base class
 */
#include "BaseWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

/**
 * Null just 0
 */

void NullWave::setOutputForTime(
	float * output,
	uint32_t nframes,
	float_t volume = 1.0
) {

	//loop frames
	for( int i = 0; i < nframes; i ++ ) {

		output[i] = 0.0;

	}

};

} } } }
