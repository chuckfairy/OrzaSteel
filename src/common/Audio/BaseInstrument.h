/**
 * Base instrument virtual class
 */
#pragma once

#include <cstdint>
#include <vector>

namespace Orza { namespace Steel { namespace Audio {

class BaseInstrument {

	public:

		/**
		 * Get pitches main method
		 */

		virtual vector<float_t> getPitches();

	protected:

		BaseInstrument() {};
		~BaseInstrument() {};

};

} } }
