/**
 * Bridge module
 */
#include <iostream>

#include <Util/Numbers.h>
#include <Util/Vector.h>

#include <Color/Color.h>

#include "Bridge.h"
#include "AreaData.h"

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

    setAttribute( Qt::WA_AcceptTouchEvents, true );

	setupLayout();

};


/**
 * Main string setter
 */

void Bridge::setNumStrings( uint8_t numStrings ) {

	clearArea();

	std::cout << "NUM STRINSDGOINSDGO " << numStrings << "\n";

	while( numStrings ) {

		-- numStrings;
		_areas[ numStrings ]->show();

	}

};


/**
 * Clear old string area
 */

void Bridge::clearArea() {

	QLayoutItem * item;

	if( _areas.size() == 0 ) {

		int maxStrings = 50; //@TODO
		int maxColor = 12; //@TODO
		int stringNum = 0;

		while( maxStrings ) {

			-- maxStrings;

			StringArea * area = createStringArea( stringNum );

			_layout->addWidget( area );

			_areas.push_back( area );

			++stringNum;
			if( stringNum >= maxColor) {
				stringNum = 0;
			}

		}

	}

	int al = _areas.size();
	for( int i = 0; i < al; ++ i ) {
		_areas[i]->hide();
	}

};


/**
 * String down index handlers
 */

void Bridge::setStringDown( uint8_t index ) {

	if ( ! Util::Vector::has<uint8_t>( &_hand, index ) ) {

		_hand.push_back( index );

		_areas[ index ]->setActive( true );

		HAS_CHANGE = true;

	}

	std::cout << "String Down : " << unsigned(index) << "\n";

};

void Bridge::setStringUp( uint8_t index ) {

	if ( Util::Vector::has<uint8_t>( &_hand, index ) ) {

		Util::Vector::remove<uint8_t>( &_hand, index );

		_areas[ index ]->setActive( false );

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

	AreaData * data = new AreaData;

	data->color = STEPS_13[ index ];
	data->label = Orza::Numbers::ROMAN_13[ index ];

	StringArea * area = new StringArea( data );

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
