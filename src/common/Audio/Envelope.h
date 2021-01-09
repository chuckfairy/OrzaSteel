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

struct Envelope {

	/**
	 * Props
	 */

	float_t attack = 0.0;

	float_t decay = 0.0;

	float_t sustain = 1.0;

	float_t release = 1.0;


	/**
	 * Helpers
	 */

	Envelope(
		float_t attack_ = 2.0,
		float_t decay_ = 0.0,
		float_t sustain_ = 1.0,
		float_t release_ = 0.0
	) {
		attack = attack_;
		decay = decay_;
		sustain = sustain_;
		release = release_;
	};

	Envelope clone() {

		return Envelope(
			attack,
			decay,
			sustain,
			release
		);

	};

};

static const Envelope DefaultEnvelope();

} }
