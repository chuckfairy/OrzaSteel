/**
 * String instrument frequency instrument
 */
#include <iostream>

#include <Util/Vector.h>

#include "StringInstrument.h"


using std::map;
using std::vector;


namespace Orza { namespace Steel { namespace Audio {


/**
 * Instrument vector types
 */

vector<float_t> StringInstrument::TYPE_DEFAULT = { 440 };

vector<float_t> StringInstrument::TYPE_COUNTRY_NECK = {
	130.81,
	164.81,
	196,
	220,
	261.63,
	329.63
};

vector<float_t> StringInstrument::NECK_STEEL_STANDARD_10 = {
	123.47, //B2
	146.83, //D3
	164.81, //E3
	185.00, //F#3
	207.65, //G#3
	246.94, //B3
	329.63, //E4
	415.30, //G#4
	554.37, //D#5
	739.99 //F#5
};

//vector<float_t> TYPE_GUITAR_STANDARD;


/**
 * Pedals
 *
 * http://steelguitaramerica.com/instruction/tuning/copedentexplained.shtml
 *
 * Names of Pedals and Levers:
 * A - Raises strings 5 and 10 two semitones
 * B - Raises strings 3 and 6 one semitone
 * C - Raises strings 4 and 5 two semitones
 * X - Lowers strings 3 and 6 one semitone
 * LL- Raises strings 4 and 8 one semitone
 * LV - Lowers strings 5 and 10 one semitone
 * LR - Lowers strings 4 and 8 one semitone
 * RL - Raises strings 1 and 7 one semitone
 * RR - Lowers strings 2 two semitones and string 9 one semitone
 *
 * 10 is this highest in this chart
 * 0 would actually line up with 10 here
 */

vector<Pedal*> StringInstrument::PEDAL_STANDARD_10 = {
	new Pedal( "X", { 3, 4 }, -1, 'x' ),
	new Pedal( "A", { 5, 0 }, 2, 'a' ),
	new Pedal( "B", { 7, 4 }, 1, 'b' ),
	new Pedal( "C", { 5, 6 }, 2, 'c' ),
	new Pedal( "LL knee(l)", { 3, 7 }, 1, 'l' ),
	new Pedal( "LV knee(k)", { 4, 9 }, 1, 'k' ),
	new Pedal( "LR knee(j)", { 3, 7 }, 1, 'j' ),
	new Pedal( "RL knee(t)", { 0, 6 }, 1, 't' ),
	new Pedal( "RR knee(r)", { 1 }, 2, 'r' ),
	new Pedal( "RR knee 2", { 8 }, 1, 'r' ),
};


/**
 * Constructs
 */

StringInstrument::StringInstrument() {

};

StringInstrument::StringInstrument( vector<float_t> strings ) {

	setStrings( strings );

};


/**
 * Getters
 */

uint8_t StringInstrument::getNumStrings() {

	return _strings.size();

};

/**
 * String setters
 */

void StringInstrument::setStrings( vector<float_t> newStrings ) {

	_strings.clear();

	Util::Vector::append( &_strings, newStrings );

};

void StringInstrument::setString( uint8_t num, float_t freq ) {

	_strings[num] = freq;

};


/**
 * Main pitches getter
 */

vector<float_t> StringInstrument::getPitches( map<uint8_t, float_t> hand ) {

	vector<float_t> out;

	map<uint8_t, float_t>::const_iterator it;

	for ( it = hand.begin(); it != hand.end(); ++ it ) {

		out.push_back( getPitch( it->first, it->second ) );

	}

	return out;

};


/**
 * Get pitches assuming position 0
 */

vector<float_t> StringInstrument::getPitches( vector<uint8_t> hand ) {

	vector<float_t> out;

	for( int i = 0; i < hand.size(); ++ i ) {

		out.push_back( _strings[ hand[ i ] ] );

	}

	return out;

};


/**
 * Pedal adding
 */

void StringInstrument::clearPedals() {

	_pedals.clear();

};

void StringInstrument::addPedal( Pedal * pedal ) {

	_pedals.push_back( pedal );

};

void StringInstrument::addPedals( vector<Pedal*> pedals ) {

	for( int i = 0; i < pedals.size(); ++ i ) {

		addPedal( pedals[ i ] );

	}

};


/**
 * get singular pitch
 */

float_t StringInstrument::getPitch( uint8_t num, uint8_t position ) {

	//@TODO check
	//throw runtime_error( "0-100 only" )

	float_t modifier = getPedalModifier( num );

	float_t starting = _strings[ num ] + modifier;

	return (float_t)( starting + ( starting * ( (float_t)position / (float_t)100 ) ) );

};


/**
 * Pedal modifier frequency
 * zero if nothing added
 */

float_t StringInstrument::getPedalModifier( uint8_t stringNum ) {

	int size = _pedals.size();

	float_t freq = 0.0;

	for( int i = 0; i < size; ++ i ) {

		Pedal * pedal = _pedals[ i ];

		if( ! pedal->on ) {
			continue;
		}

		int pedalStrings = pedal->strings.size();

		for( int t = 0; t < pedalStrings; ++ t ) {

			uint8_t pedalString = pedal->strings[ t ];

			if( pedalString != stringNum ) {
				continue;
			}

			float_t stringFreq = _strings[ pedalString ];

			float stepsAbs = abs( pedal->steps );

			float_t percent = pow( 2.0, stepsAbs / 12.0 ) - 1;

			float_t pedalFreq = stringFreq * percent;

			freq += ( pedal->steps > 0 )
				? pedalFreq
				: -pedalFreq;

		}

	}

	return freq;

};

} } }
