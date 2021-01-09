/**
 * Wavefrom base class
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <Util/Vector.h>
#include <Audio/Envelope.h>


using std::map;
using std::vector;

using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


class BaseWave {

	public:

		/**
		 * Get frequency value on -1.0 to 1.0
		 * Maybe overly complicated
		 * This should also update the time based on the delta
		 */

		void setOutputForTime(
			float * output,
			uint32_t nframes,
			Envelope * env,
			float_t volume = 1.0
		);


		virtual float_t getRampSignal( Envelope *, float_t ) {};

		/**
		 * Main setter for data
		 */

		void setWave(
			vector<float_t> newFreqs,
			uint32_t newRate
		);

		void setDelta( float_t newDelta ) {

			_delta = newDelta;

		};

		void setThreshold( float_t newThres ) {

			_threshold = newThres;

		};


		/**
		 * Envelope data
		 */
		float_t getVolumeFromEnvelope( Envelope * env, float_t ramp );


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
		vector<float_t> _offFreqs;

		uint32_t _rate;

		vector<float_t> _ramps;

		//Used for Envelope to ramp
		map<float, long> _rampTimes;
		map<float, long> _rampTimesOff;

};

} } } }
