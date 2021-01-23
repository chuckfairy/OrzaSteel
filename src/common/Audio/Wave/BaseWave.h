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


		virtual float_t getRampSignal( Envelope *, float_t ramp ) {};

		/**
		 * Main setter for data
		 */

		void setWave(
			map<uint8_t, float_t> newFreqs,
			uint32_t newRate
		);

		void setDelta( float_t newDelta ) {

			_delta = newDelta;

		};

		void setThreshold( float_t newThres ) {

			_threshold = newThres;

		};

		float_t getFrequencyRamp(float_t noteFrequency, float_t ramp);


		/**
		 * Envelope data
		 */
		float_t getVolumeFromEnvelope( Envelope * env, uint8_t ramp );


	protected:

		BaseWave() {};
		~BaseWave() {};


		/**
		 * Props
		 */

		float_t _ramp = 0.0;

		float_t _delta = 2.0;

		float_t _threshold = 1.0;

		map<uint8_t, float_t> _freqs;
		map<uint8_t, float_t> _offFreqs;
		map<uint8_t, bool> _rampTimesOn;

		uint32_t _rate;

		map<uint8_t, float_t> _ramps;

		//Used for Envelope to ramp
		map<uint8_t, long> _rampTimes;
		map<uint8_t, float_t> _lastVolume;
		//map<uint8_t, long> _rampTimesOff;

		float_t getOutputFromFrequencyAndRamp(float_t frequency, float_t ramp);

};

} } } }
