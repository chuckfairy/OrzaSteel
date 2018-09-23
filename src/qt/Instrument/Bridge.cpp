/**
 * Bridge module
 */
#include <iostream>

#include <Util/Vector.h>

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

};


/**
 * Main string setter
 */

void Bridge::setNumStrings( uint8_t numStrings ) {

	clearArea();

	for( uint8_t i = 0; i < numStrings; ++ i ) {

		StringArea * area = createStringArea( i );

		_layout->addWidget( area );

		_areas.push_back( area );

	}

};


/**
 * Clear old string area
 */

void Bridge::clearArea() {

	_areas.clear();

	QLayoutItem * item;

	while( ( item = _layout->takeAt( 0 ) ) ) {

		if( item->widget() ) {

			delete item->widget();

		}

		delete item;

	}

};


/**
 * String down index handlers
 */

void Bridge::setStringDown( uint8_t index ) {

	if ( ! Util::Vector::has<uint8_t>( &_hand, index ) ) {

		_hand.push_back( index );

		HAS_CHANGE = true;

	}

	std::cout << "String Down : " << unsigned(index) << "\n";

};

void Bridge::setStringUp( uint8_t index ) {

	if ( Util::Vector::has<uint8_t>( &_hand, index ) ) {

		Util::Vector::remove<uint8_t>( &_hand, index );

		HAS_CHANGE = true;

	}

	std::cout << "String Up : " << unsigned(index) << "\n";

};


/**
 * String area handlers
 */

void Bridge::handleStringDown( StringArea * area ) {

	uint8_t index = getIndexFromStringArea( area );

	setStringDown( index );

};

void Bridge::handleStringUp( StringArea * area ) {

	uint8_t index = getIndexFromStringArea( area );

	setStringUp( index );

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
