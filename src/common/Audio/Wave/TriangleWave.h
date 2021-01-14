/**
 * Wavefrom base class
 */
#pragma once

#include "BaseWave.h"


using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

class TriangleWave : public BaseWave {

	public:

		static float_t DOUBLE_PI;


		TriangleWave() {};
		~TriangleWave() {};

		/**
		 * Ramp grabber
		 */

		vector<float_t> _sines;

		float_t getRampSignal( Envelope *, float_t ramp );

};

} } } }
