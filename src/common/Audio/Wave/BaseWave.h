/**
 * Wavefrom base class
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <Util/Vector.h>


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


class BaseWave {

	public:

		/**
		 * Get frequency value on -1.0 to 1.0
		 * Maybe overly complicated
		 * This should also update the time based on the delta
		 */

		virtual void setOutputForTime(
			float * output,
			uint32_t nframes,
			float_t volume = 1.0
		) {};


		/**
		 * Main setter for data
		 */

		void setWave(
			vector<float_t> newFreqs,
			uint32_t newRate
		) {

			_freqs.clear();
			_ramps.clear();

			_rate = newRate;

			for( int i = 0; i < newFreqs.size(); ++ i ) {

				_freqs.push_back( newFreqs[ i ] / _rate );

				_ramps.push_back( 0.0 );

			}

		};

		void setDelta( float_t newDelta ) {

			_delta = newDelta;

		};

		void setThreshold( float_t newThres ) {

			_threshold = newThres;

		};


	protected:

		BaseWave() {};
		~BaseWave() {};


		/**
		 * Props
		 */

		float_t _ramp = 0.0;

		float_t _delta = 2.0;

		float_t _threshold = 1.0;

		vector<float_t> _freqs;

		uint32_t _rate;

		vector<float_t> _ramps;

};

} } } }
