/**
 * Wavefrom base class
 */
#pragma once

#include "BaseWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {

class TriangleWave : public BaseWave {

	public:

		static float_t DOUBLE_PI;


		TriangleWave() {};
		~TriangleWave() {};

		/**
		 * Sine wave impl of output
		 */

		void setOutputForTime(
			float * output,
			uint32_t nframes,
			float_t volume = 1.0
		);


	private:

		/**
		 * Internal
		 */

        vector<float_t> _sines;

		float_t getRampSignal( float_t volume );

};

} } } }
