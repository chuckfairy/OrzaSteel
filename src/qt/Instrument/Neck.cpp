/**
 * Neck impl
 */
#include <cmath>

#include <Color/Color.h>

#include "FretArea.h"

#include "Neck.h"


using namespace Orza::Steel::Color;


namespace Orza { namespace Steel { namespace Instrument {


/**
 * constructor
 */

Neck::Neck() {

	//setupBridgeUIHelper();

	_Bar = new Tonebar( this );

	_positions.push_back( 0.0 );

	QSizePolicy sizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	setSizePolicy( sizePolicy );

	setStyleSheet(
		"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	);

	setMouseTracking(true);
	_Bar->setMouseTracking(true);

	show();

};


/**
 * Positions getter
 */

vector<float_t> Neck::getPositions() {

	return _positions;

};


/**
 * Helper UI for display frets more or less
 */

void Neck::setupBridgeUIHelper() {

	int semiTones = 12; //@TODO move further down line

	float widthSoFar = 0;

	for( int i = 0; i < semiTones; ++ i ) {

		//Get division and prepare for base 10
		float semiWidth = ( (float)i / (float)semiTones )
			/ ( (float)i / 10 );

		semiWidth = ( log(semiWidth) * (float) width() ) - widthSoFar;
		const char * color = STEPS_12[ i ];

		FretArea * area = new FretArea( color );
		area->setParent( this );
		area->setGeometry( widthSoFar, 0, semiWidth, 200 );
		area->move( widthSoFar, 0 );
		area->setMouseTracking( true );

		widthSoFar += semiWidth;

	}

};


/**
 * Mouse move and tonebar setting
 */

void Neck::mouseMoveEvent( QMouseEvent * event ) {

	std::cout << "Mouse move : " << event->x() << " " << event->y() << "\n";

	_positions[ 0 ] = ( (float_t)event->x() / (float_t)width() ) * (float_t)100;

	std::cout << "Position : " << _positions[ 0 ] << " " << width() << "\n";

	HAS_CHANGE = true;

	_Bar->move( event->x() - ( _Bar->width() / 2 ), 0 );

};

} } }
