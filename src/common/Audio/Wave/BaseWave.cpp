/**
 * Wavefrom base class
 */
#include <iostream>
#include <algorithm>

#include "BaseWave.h"

using std::vector;
using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


/**
 * Output for time abstract
 */

void BaseWave::setOutputForTime(
	float * output,
	uint32_t nframes,
	Envelope * env,
	float_t volume
) {

	//loop frames

	for( uint32_t i = 0; i < nframes; ++ i ) {

		output[i] = getRampSignal( env, volume );

	}

};


/**
 * Main setter for data
 */

void BaseWave::setWave(
	vector<float_t> newFreqs,
	uint32_t newRate
) {

	_offFreqs = _freqs;
	_freqs.clear();
	//_ramps.clear();

	int rampSize = _ramps.size() - 1;

	_rate = newRate;

	for( int i = 0; i < (int)newFreqs.size(); ++ i ) {

		float freqRate = newFreqs[ i ] / _rate;
		_freqs.push_back(freqRate);

		//Off frequency for release usage
		if(Util::Vector::has<float_t>(&_offFreqs, freqRate)) {
			Util::Vector::remove<float_t>(&_offFreqs, freqRate);
			_rampTimes.erase(freqRate);
			_rampTimesOff[freqRate] = 0;
			continue;
		}

		if(!_rampTimes.count(freqRate)) {
			_rampTimes[freqRate] = 0;
		}

		if( rampSize < i )  {

			_ramps.push_back( 0.0 );

		}

	}

};

/**
 * Envelope data
 */
float_t BaseWave::getVolumeFromEnvelope( Envelope * env, float_t ramp ) {

	//Release
	if(_rampTimesOff.count(ramp) && false) {
		if(env->release <= 0) {
			return 0;
		}

		float release = env->release * _rate;

		float_t vol = ( release - _rampTimesOff[ramp] ) / release;
		return vol < 0
			? 0
			: vol;
	}

	float attack = env->attack * _rate;
	float rampTime = ((float)_rampTimes[ramp]) * ((float)_rate);

	std::cout << "Attack " << attack << " " << _rampTimes[ramp] << " " << _rate << "\n";

	float vol = std::min<float>(1.0f, _rampTimes[ramp] / attack);

	return vol;

}

} } } }
