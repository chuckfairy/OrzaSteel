/**
 * String instrument frequency instrument
 */
#include "StringInstrument.cpp"


using std::map;
using std::vector;


namespace Orza { namespace Instrument {


/**
 * Instrument vector types
 */

vector<float_t> StringInstrument::TYPE_DEFAULT = { 440 };

static vector<float_t> StringInstrument::TYPE_COUNTRY_NECK = {
	261,
	329,
	392,
	440,
	523,
	659
};


/**
 * Constructs
 */

StringInstrument() {

};

StringInstrument::StringInstrument( vector<float_t> strings ) {

	setStrings( strings );

};


/**
 * String setters
 */

void StringInstrument::setStrings( vector<float_t> newStrings ) {

	_strings.clear();

	_strings.insert(
		std::end( _strings ),
		std::begin( newStrings ),
		std::end( newStrings )
	);

};

void StringInstrument::setString( uint8_t num, float_t freq ) {

	_strings[num] = freq;

};


/**
 * Main pitches getter
 */

vector<float_t> StringInstrument::getPitches( map<uint8_t, uint8_t> hand ) {

	vector<float_t> out;

	for( uint8_t const& [stringNum, position] : hand ) {

		out.push_back( getPitch( stringNum, position ) );

	}

	return out;

};

float_t StringInstrument::getPitch( uint8_t num, uint8_t position ) {

	//@TODO check
	//throw runtime_error( "0-100 only" )

	float_t starting = _strings[ num ];

	return starting + ( starting * ( position / 100 ) );

};

} }
