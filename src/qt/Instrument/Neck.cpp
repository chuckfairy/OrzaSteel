/**
 * Neck impl
 */
#include <cmath>
#include <algorithm>

#include <Color/Color.h>
#include <Util/Numbers.h>

#include "Neck.h"
#include "AreaData.h"


using namespace Orza::Steel::Color;


namespace Orza { namespace Steel { namespace Instrument {


/**
 * constructor
 */

Neck::Neck() {

	_Bar = new Tonebar( this );

	handleResize();

	_positions.push_back( 0.0 );

	QSizePolicy sizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	setSizePolicy( sizePolicy );

	//setStyleSheet(
		//"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	//);

	setAttribute( Qt::WA_AcceptTouchEvents, true );
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
 * Resize handler
 */

void Neck::handleResize() {

	setupBridgeUIHelperLog();

	_Bar->raise();

};


void Neck::resizeEvent( QResizeEvent *event ) {

	handleResize();
	QWidget::resizeEvent(event);

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
		area->setGeometry( 0, 0, semiWidth, height() / 2 );
		area->move( widthSoFar, 0 );
		area->setMouseTracking( true );

		widthSoFar += semiWidth;

	}

};


/**
 * Helper UI for display frets more or less
 */

void Neck::setupBridgeUIHelperLog() {

	//clearArea();

	int toneNumbers = _semiTones * _octaves;

	float widthSoFar = 0.0;
	float fullWidth = (float) width();
	float percent = 0.0;
	float heightChild = height() - 10;

	float widthSplit = fullWidth / (toneNumbers);

	if( _areas.size() == 0 ) {
		for( int i = 0; i < toneNumbers; ++ i ) {
			int labelIndex = i - (_semiTones * floor(i / _semiTones));

			const char * color = STEPS_13[ labelIndex ];
			const char * label = Orza::Numbers::ROMAN_13[ labelIndex ];

			AreaData * data = new AreaData();
			data->color = color;
			data->label = label ;

			FretArea * area = new FretArea( data );
			area->setParent( this );
			_areas.push_back(area);
		}
	}

	for( int i = 0; i < toneNumbers; ++ i ) {

		//@TODO actual log to move to
		//different calc private functions
		//float_t semiWidth = pow( 2, ( (toneNumbers - i) / toneNumbers) ) - pow(2, ((toneNumbers - i - 1) / toneNumbers));

		float_t semiWidth = widthSplit;

		percent += semiWidth;

		FretArea * area = _areas[i];

		area->setGeometry( 0, 0, semiWidth, heightChild );
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

	//@TODO this is linear to log conversion
	//but move depending on neck setup
	float_t neckPercentage =  (float_t)event->x() / (float_t)width();
	neckPercentage *= _octaves;

	_positions[0] = neckPercentage * (float_t)100;
	_positions[0] = std::min(_positions[0], (float_t)(100.0 * _octaves));
	_positions[0] = std::max(_positions[0], (float_t)0.0);

	//std::cout << "Position : " << _positions[ 0 ] << " " << width() << "\n";

	HAS_CHANGE = true;

	_Bar->move( event->x() - ( _Bar->width() / 2 ), 0 );

};

/**
 * Clear old string area
 */

void Neck::clearArea() {

	int al = _areas.size();
	for( int i = 0; i < al; ++ i ) {

		_areas[i]->setParent(0);
		delete _areas[i];

	}

	_areas.clear();

};

} } }
