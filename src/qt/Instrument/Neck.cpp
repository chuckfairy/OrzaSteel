/**
 * Neck impl
 */
#include <cmath>

#include <Color/Color.h>
#include <Util/Numbers.h>

#include "FretArea.h"

#include "Neck.h"
#include "AreaData.h"


using namespace Orza::Steel::Color;


namespace Orza { namespace Steel { namespace Instrument {


/**
 * constructor
 */

Neck::Neck() {

	//setupBridgeUIHelper();
	setupBridgeUIHelperLog();

	_Bar = new Tonebar( this );

	_positions.push_back( 0.0 );

	QSizePolicy sizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	setSizePolicy( sizePolicy );

	//setStyleSheet(
		//"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	//);

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

	float semiTones = 12; //@TODO move further down line

	float widthSoFar = 0.0;
	float fullWidth = (float) width();
	float widthSplit = fullWidth / (semiTones - 1.5);

	for( int i = 0; i < semiTones; ++ i ) {

		float semiWidth = widthSplit;

		const char * color = STEPS_13[ i ];
		const char * label = Orza::Numbers::ROMAN_13[ i ];

		AreaData * data = new AreaData();
		data->color = color;
		data->label = label ;

		FretArea * area = new FretArea( data );
		area->setParent( this );
		area->setGeometry( 0, 0, semiWidth, 200 );
		area->move( widthSoFar, 0 );
		area->setMouseTracking( true );

		widthSoFar += semiWidth;

	}

};


/**
 * Helper UI for display frets more or less
 */

void Neck::setupBridgeUIHelperLog() {

	float semiTones = 12; //@TODO move further down line

	float widthSoFar = 0.0;
	float fullWidth = (float) width() + 100;
	float percent = 0.0;

	for( int i = 0; i < semiTones; ++ i ) {

		float_t semiWidth = pow( 2, ( (semiTones - i) / semiTones) ) - pow(2, ((semiTones - i - 1) / semiTones));

		std::cout << semiWidth << "\n";

		percent += semiWidth;

		semiWidth = ( semiWidth * fullWidth );

		std::cout << semiWidth << "\n";

		const char * color = STEPS_13[ i ];
		const char * label = Orza::Numbers::ROMAN_13[ i ];

		AreaData * data = new AreaData();
		data->color = color;
		data->label = label ;

		FretArea * area = new FretArea( data );
		area->setParent( this );
		area->setGeometry( 0, 0, semiWidth, height() * .5 );
		area->move( widthSoFar, 0 );
		area->setMouseTracking( true );
		area->raise();

		widthSoFar += semiWidth;

	}

};


/**
 * Mouse move and tonebar setting
 */

void Neck::mouseMoveEvent( QMouseEvent * event ) {

	//std::cout << "Mouse move : " << event->x() << " " << event->y() << "\n";

	_positions[ 0 ] = ( (float_t)event->x() / (float_t)width() ) * (float_t)100;

	//std::cout << "Position : " << _positions[ 0 ] << " " << width() << "\n";

	HAS_CHANGE = true;

	_Bar->move( event->x() - ( _Bar->width() / 2 ), 0 );

};

} } }
