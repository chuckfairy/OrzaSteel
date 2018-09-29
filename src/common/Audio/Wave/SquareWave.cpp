/**
 * Wavefrom base class
 */
#include "SquareWave.h"


using std::vector;


namespace Orza { namespace Steel { namespace Audio { namespace Wave {


float_t SquareWave::DOUBLE_PI = 2 * M_PI;


/**
 * Main output
 */

void SquareWave::setOutputForTime(
	float * output,
	uint32_t nframes,
	float_t volume
) {

	//loop frames

	for( uint32_t i = 0; i < nframes; ++ i ) {

		output[i] = volume * getRampSignal( volume );

	}

};


/**
 * Main signal math for chords
 * triangle wave from a sine wave
 *
 * https://stackoverflow.com/questions/7400834/creating-a-triangle-wave-from-a-sine-wave-in-c
 *
 */

float_t SquareWave::getRampSignal( float_t volume ) {

	float_t out = 0.0;

	int freqSize = _freqs.size();

	float_t volPer = freqSize == 1
		? volume
		: (volume / (float_t) _freqs.size());

    float_t deltaVol = volPer * 1;

	for( int i = 0; i < _freqs.size(); ++ i ) {

		//Get

		float_t noteFrequency = _freqs[ i ];

		float_t ramp = _ramps[ i ];


		//Check threwshold from add

		ramp += noteFrequency;

		if( ramp > _threshold ) {

			ramp -= _delta;

		}


		//Set ramp for next time

		_ramps[ i ] = ramp;


        //Last sine usage
        //@TODO move

        int sineSize = _sines.size() - 1;
        if( sineSize < i ) {

            _sines.push_back( 0.0 );

        }


		//Get sine signal

		float_t sig = sin( DOUBLE_PI * ramp );

        out += ( sig >= 0 )
            ? deltaVol
            : -deltaVol;

	}

	return out;

};

} } } }
