/**
 * Envelope struct
 *
 * attack, decay, and release in seconds
 * must use sample rate outside of this
 *
 * sustain in percentage 0-1.0
 */
#pragma once

#include <cmath>
#include <cstdint>


namespace Orza { namespace Audio {


/**
 * Main struct
 */

class Envelope {

	public:

		/**
		 * Helpers
		 */
		Envelope(float_t rate);

		//Setters
		void setAttack(float_t);
		void setDecay(float_t);
		void setSustain(float_t);
		void setRelease(float_t);
		void setRate(float_t);

		//Getters
		float_t getAttack();
		float_t getDecay();
		float_t getSustain();
		float_t getRelease();
		float_t getRate();

	private:

		/**
		 * Props
		 */

		float_t attack = 1.0;

		float_t decay = 0.0;

		float_t sustain = 1.0;

		float_t release = 1.0;

		float_t rate = 44100;


};

static const Envelope DefaultEnvelope();

} }
