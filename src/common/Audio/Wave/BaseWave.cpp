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

	int freqSize = _freqs.size();

	float_t volPer = freqSize == 1
		? volume
		: (volume / (float_t) _freqs.size());

	map<uint8_t, float_t>::iterator it;

	float_t rampVolume = 0.0f;
	float_t ramp = 0.0f;
	float_t noteFrequency = 0.0f;

	//Nframes
	for( uint32_t i = 0; i < nframes; ++ i ) {

		output[i] = 0;

		//Frequency loop
		for(it = _freqs.begin(); it != _freqs.end(); ++it) {

			if(_rampTimesFinished[it->first]) {
				continue;
			}

			//Getters
			noteFrequency = it->second;

			ramp = getFrequencyRamp(noteFrequency, _ramps[ it->first ]);

			//Frequency from volPer and Envelope
			rampVolume = getVolumeFromEnvelope(env, it->first);

			if(_rampTimesOn[it->first]) {
				_lastVolume[ it->first ] = rampVolume;
			} else {
				if(rampVolume == 0) {
					_rampTimesFinished[it->first] = true;
					continue;
				}
			}

			//Abstract grabber for signal
			output[i] += getRampSignal( env, ramp ) * volPer * rampVolume;


			//Set ramp for next time
			_ramps[ it->first ] = ramp;

			//std::cout << "Frequency Volume " << (float)_lastVolume[ it->first ] << "\n";

			//Ramp times for Envelope
			++ _rampTimes[ it->first ];

		}
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

	//_offFreqs = _freqs;
	//_freqs.clear();
	//_ramps.clear();

	int rampSize = _ramps.size() - 1;

	_rate = newRate;

	float freqRate;

	for(it = newFreqs.begin(); it != newFreqs.end(); ++it) {

		freqRate = it->second / _rate;
		//_freqs.push_back(freqRate);
		_freqs[it->first] = freqRate;
		//_offFreqs[it->first] = 0;

		//Start ramp time for attack
		if( _rampTimes.count( it->first ) != 1 || !_rampTimesOn[it->first] ) {
			//std::cout << (int)it->first << "\n";
			_rampTimes[it->first] = 0;
		}

		_rampTimesOn[it->first] = true;
		_rampTimesFinished[it->first] = false;

		if( _ramps.count( it->first ) != 1 )  {

			_ramps[it->first] = 0.0;

		}

	}

	//Off ramp time checks
	map<uint8_t, long>::iterator rt = _rampTimes.begin();
	while( rt != _rampTimes.end() ) {
		if( _rampTimesOn[rt->first] && newFreqs.find(rt->first) == newFreqs.end() ) {
			//std::cout << "Erasing " << (int)rt->first << "\n";
			_rampTimes[rt->first] = 0;
			_rampTimesOn[rt->first] = false;
			//_rampTimesFinished[rt->first] = false;
			//_freqs[rt->first] = 0;
			//_offFreqs[rt->first] = rt->second;

			//_freqs[rt->first] = 0;
			//_freqs.erase(_freqs.find(rt->first));
			//continue;
		}

		++rt;
	}

};

/**
 * Envelope data
 */
float_t BaseWave::getVolumeFromEnvelope( Envelope * env, uint8_t ramp ) {

	float rampTime = _rampTimes[ramp];
	float vol = 1.0f;

	//Release
	if(!_rampTimesOn[ramp]) {
		float release = env->getRelease();

		if(release <= 0) {
			return 0;
		}

		vol = _lastVolume[ramp] - ((rampTime / release) * (float)_lastVolume[ramp]);
		return vol < 0
			? 0
			: vol;
	}

	//ADS

	if(rampTime < env->getAttack()) {
		//Attack
		vol = std::min<float>(1.0f, rampTime / env->getAttack());
	} else if((rampTime - env->getAttack()) < env->getDecay()) {
		//Decay
		vol = std::max<float>(
			env->getSustain(),
			1.0f - ((rampTime - env->getAttack()) / env->getDecay())
		);
	} else {
		//Sustain
		vol = env->getSustain();
	}

	return vol;

}

float_t BaseWave::getFrequencyRamp(float_t noteFrequency, float_t ramp) {

	//Check threshold from add
	ramp += noteFrequency;

	if( ramp > _threshold ) {
		ramp -= _delta;
	}

	return ramp;

};


} } } }
