/**
 * Wavefrom base class
 */
#pragma once

#include "BaseWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

class SquareWave : public BaseWave {

	public:

		static float_t DOUBLE_PI;


		SquareWave();
		~SquareWave() {};

		/**
		 * Ramp grabber
		 */

		float_t getRampSignal( Envelope *, float_t ramp );


};

} } } }
