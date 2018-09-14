/**
 * Bridge module
 */
#include "Bridge.h"

namespace Orza { namespace Steel { namespace Instrument {

Bridge::Bridge() {

	setNumStrings( 1 );

};


/**
 * Main string setter
 */

void Bridge::setNumStrings( uint8_t numStrings ) {

	_areas.clear();

	for ( uint8_t i = 0; i < numStrings; ++ i ) {

		StringArea * area = createStringArea( i );

		_areas.push_back( area );

	}

};


/**
 * Main constructor
 */

StringArea * Bridge::createStringArea( uint8_t index ) {

	const char * color = "#FF0000";

	return new StringArea( color );

};

}; }; };
