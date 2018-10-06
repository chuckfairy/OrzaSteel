/**
 * String instrument frequency instrument
 */
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

//vector<float_t> TYPE_GUITAR_STANDARD;


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

	float_t starting = _strings[ num ];

	float_t modifier = getPedalModifier( num );

	return (float_t)( starting + ( starting * ( (float_t)position / (float_t)100 ) ) + modifier );

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

		int pedalStrings = pedal->strings.size();

		if( ! pedal->on ) {
			continue;
		}

		for( int t = 0; i < pedalStrings; ++ t ) {

			uint8_t pedalString = pedal->strings[ t ];

			if( pedalString > ( _strings.size() - 1 ) ) {
				continue;
			}

			float_t stringFreq = _strings[ pedalString ];

			float_t pedalFreq = stringFreq * pow( 2.0, pedal->steps / 12 );

			freq += pedalFreq;

		}

	}

	return freq;

};

} } }
