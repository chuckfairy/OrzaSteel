/**
 * Wavefrom base class
 */
#pragma once

#include "BaseWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

class SineWave : public BaseWave {

	public:

		static float_t DOUBLE_PI;


		SineWave() {};
		~SineWave() {};


		/**
		 * Rampe signal per vol
		 */

		float_t getRampSignal( Envelope * env, float_t ramp );

};

} } } }
