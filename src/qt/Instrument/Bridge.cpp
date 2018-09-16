/**
 * Bridge module
 */
#include <iostream>

#include <Color/Color.h>

#include "Bridge.h"

#include "Events/StringDownEvent.h"
#include "Events/StringUpEvent.h"


using namespace Orza::Steel::Color;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Construct
 */

Bridge::Bridge() {

	_downEvent = new StringDownEvent<Bridge, StringArea>( this );
	_upEvent = new StringUpEvent<Bridge, StringArea>( this );

	setupLayout();

	setNumStrings( 2 );

};


/**
 * Main string setter
 */

void Bridge::setNumStrings( uint8_t numStrings ) {

	_areas.clear();

	for( uint8_t i = 0; i < numStrings; ++ i ) {

		StringArea * area = createStringArea( i );

		_layout->addWidget( area );

		_areas.push_back( area );

	}

};


/**
 * String area handlers
 */

void Bridge::handleStringUp( StringArea * area ) {

	std::cout << unsigned(getIndexFromStringArea( area )) << "\n";

};

void Bridge::handleStringDown( StringArea * area ) {

	std::cout << unsigned(getIndexFromStringArea( area )) << "\n";

};


/**
 * Main constructor
 */

StringArea * Bridge::createStringArea( uint8_t index ) {

	const char * color = STEPS_12[ index ];

	StringArea * area = new StringArea( color );

	area->on( StringArea::EVENT_DOWN, _downEvent );
	area->on( StringArea::EVENT_UP, _upEvent );

	return area;

};


/**
 * setup widget layout
 */

void Bridge::setupLayout() {

	_layout = new QVBoxLayout();
	_layout->setSpacing( 0 );
	_layout->setContentsMargins(0, 0, 0, 0);

	setLayout( _layout );

};


/**
 * Get index helper
 */

uint8_t Bridge::getIndexFromStringArea( StringArea * area ) {

	for ( uint8_t i = 0; i < _areas.size(); ++ i ) {

		if ( _areas[ i ] == area ) {

			return i;

		}

	}

	//@TODO error
	return 0;

};

} } }
