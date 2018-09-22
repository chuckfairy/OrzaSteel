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
	659.26,
	523.25,
	440,
	392,
	329.63,
	261.63
};

vector<float_t> StringInstrument::TYPE_COUNTRY_NECK_L = {
	261.63,
	329.63,
	392,
	440,
	523.25,
	659.26
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

vector<float_t> StringInstrument::getPitches( map<uint8_t, uint8_t> hand ) {

	vector<float_t> out;

	map<uint8_t, uint8_t>::const_iterator it;

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
 * get singular pitch
 */

float_t StringInstrument::getPitch( uint8_t num, uint8_t position ) {

	//@TODO check
	//throw runtime_error( "0-100 only" )

	float_t starting = _strings[ num ];

	return (float_t)( starting + ( starting * ( position / 100 ) ) );

};

} } }
