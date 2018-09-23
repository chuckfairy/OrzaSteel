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

		void setOutputForTime(
			float * output,
			uint32_t nframes,
			float_t volume = 1.0
		);

};

} } } }
