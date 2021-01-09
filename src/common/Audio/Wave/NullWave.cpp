/**
 * Wavefrom base class
 */
#include "NullWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

/**
 * Null just 0
 */

float_t NullWave::getRampSignal(
	float_t volume
) {

	return 0.0;

};

} } } }
