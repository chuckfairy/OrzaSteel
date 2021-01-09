/**
 * Wavefrom base class
 */
#pragma once

#include "BaseWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

class NullWave : public BaseWave {

	public:

		NullWave() {};
		~NullWave() {};

		/**
		 * Ramp grabber
		 */

		float_t getRampSignal( float_t volume );

};

} } } }
