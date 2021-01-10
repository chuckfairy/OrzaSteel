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
	map<uint8_t, float_t> newFreqs,
	uint32_t newRate
) {

	//_rampTimesOff = _rampTimes;

	map<uint8_t, float_t>::iterator it;
	int i = 0;

	//_freqs.clear();
	//_ramps.clear();

	int rampSize = _ramps.size() - 1;

	_rate = newRate;

	for(it = newFreqs.begin(); it != newFreqs.end(); ++it) {

		float freqRate = it->second / _rate;
		//_freqs.push_back(freqRate);
		_freqs[it->first] = freqRate;

		//Start ramp time for attack
		if( _rampTimes.count( it->first ) != 1 ) {
			std::cout << (int)it->first << "\n";
			_rampTimes[it->first] = 0;
		}

		if( _ramps.count( it->first ) != 1 )  {

			_ramps[it->first] = 0.0;

		}

	}

	//Off ramp time checks
	map<uint8_t, long>::iterator rt;
	for(rt = _rampTimes.begin(); rt != _rampTimes.end(); ++rt) {
		if( newFreqs.count(rt->first) != 1 ) {
			std::cout << "Erasing " << (int)rt->first << "\n";
			_rampTimes[rt->first] = 0;
			_rampTimesOff[rt->first] = 0;
			_freqs[rt->first] = 0;
			//_freqs.erase(_freqs.find(rt->first));
		}
	}

};

/**
 * Envelope data
 */
float_t BaseWave::getVolumeFromEnvelope( Envelope * env, uint8_t ramp ) {

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

	//std::cout << "Attack " << attack << " " << _rampTimes[ramp] << " " << _rate << "\n";

	float vol = std::min<float>(1.0f, _rampTimes[ramp] / attack);

	return vol;

}

} } } }
