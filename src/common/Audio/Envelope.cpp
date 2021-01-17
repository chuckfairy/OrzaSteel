/**
 * Envelope struct
 *
 * attack, decay, and release in seconds
 * must use sample rate outside of this
 *
 * sustain in percentage 0-1.0
 */
#include "Envelope.h"


namespace Orza { namespace Audio {


/**
 * Main struct
 */

Envelope::Envelope(float_t rate) :
	rate(rate)
{
	setAttack(1.0);
	setDecay(0.0);
	setSustain(1.0);
	setRelease(0.0);
}


void Envelope::setAttack(float_t attack_) {

	attack = attack_ * rate;

}

void Envelope::setDecay(float_t decay_) {

	decay = decay_ * rate;

}

void Envelope::setSustain(float_t sustain_) {

	sustain = sustain_;

}

void Envelope::setRelease(float_t release_) {

	release = release_ * rate;

}

float_t Envelope::getAttack() {

	return attack;

}

float_t Envelope::getDecay() {

	return decay;

}

float_t Envelope::getSustain() {

	return sustain;

}

float_t Envelope::getRelease() {

	return release;

}

float_t Envelope::getRate() {

	return rate;

}

} }
