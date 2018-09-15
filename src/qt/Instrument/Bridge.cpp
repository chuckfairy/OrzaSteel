/**
 * Bridge module
 */
#include <iostream>

#include "Bridge.h"


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Construct
 */

Bridge::Bridge() {

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	setupLayout();

	setNumStrings( 1 );

};


/**
 * Main string setter
 */

void Bridge::setNumStrings( uint8_t numStrings ) {

	_areas.clear();

	for ( uint8_t i = 0; i < numStrings; ++ i ) {

		std::cout << i << "TEST\n";

		StringArea * area = createStringArea( i );

		_layout->addWidget( area );

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


/**
 * setup widget layout
 */

void Bridge::setupLayout() {

	_layout = new QVBoxLayout();

	setLayout( _layout );

}

} } }
