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

	connect(
		this,
		SIGNAL( emitNeckPosition(float) ),
		this,
		SLOT( setPositions(float) )
	);

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

	setupBridgeUIHelper();

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

	static bool running = false;

	if(running) {
		return;
	}

	running = true;

	clearArea();

	int toneNumbers = _semiTones * _octaves;

	float widthSoFar = 0.0;
	float fullWidth = (float) width();
	float percent = 0.0;
	float heightChild = height();

	float widthSplit = fullWidth / (toneNumbers);

	for( int i = 0; i < toneNumbers; ++ i ) {
		int labelIndex = i - (_semiTones * floor(i / _semiTones));

		const char * color = STEPS_13[ labelIndex ];
		const char * label = Orza::Numbers::ROMAN_13[ labelIndex ];

		FretArea * area = _areas[i];

		AreaData * data = area->getData();
		data->color = color;
		data->label = label;

		float_t semiWidth = widthSplit;

		percent += semiWidth;

		area->setGeometry( 0, 0, semiWidth, heightChild );
		area->move( widthSoFar, 0 );
		area->setMouseTracking( true );

		area->render();

		area->raise();
		area->show();

		_areas.push_back(area);

		widthSoFar += semiWidth;

	}

	running = false;

};


/**
 * Mouse move and tonebar setting
 */

void Neck::mouseMoveEvent( QMouseEvent * event ) {

	//@TODO this is linear to log conversion
	//but move depending on neck setup
	float_t neckPercentage =  (float_t)event->x() / (float_t)width();

	setPositions(neckPercentage);

};


void Neck::setPositions( float value ) {

	float_t neckPercentage = value * _octaves;

	_positions[0] = neckPercentage * (float_t)100;
	_positions[0] = std::min(_positions[0], (float_t)(100.0 * _octaves));
	_positions[0] = std::max(_positions[0], (float_t)0.0);

	HAS_CHANGE = true;

	_Bar->move( ( value * width() ) - ( _Bar->width() / 2 ), 0 );

}


void Neck::setOctaves( int octaves ) {

	std::cout << "OCATVES " << octaves << "\n\n\n";
	_octaves = octaves;

	setupBridgeUIHelper();

	_Bar->raise();

};

void Neck::setSemiTones( int semi ) {

	std::cout << "SEMITONES " << semi << "\n\n\n";
	_semiTones = semi;

	setupBridgeUIHelper();

	_Bar->raise();

};

/**
 * Clear old string area
 */

void Neck::clearArea() {

	if(_areas.size() == 0) {
		//Max number of areas ever
		int toneNumbers = 12 * 4;

		for(int i = 0; i < toneNumbers; ++i) {
			int labelIndex = i - (_semiTones * floor(i / _semiTones));

			const char * color = STEPS_13[ labelIndex ];
			const char * label = Orza::Numbers::ROMAN_13[ labelIndex ];

			AreaData * data = new AreaData();
			data->color = color;
			data->label = label;

			FretArea * area = new FretArea( data );
			area->setParent( this );

			_areas.push_back(area);
		}
	}

	int al = _areas.size();
	for( int i = 0; i < al; ++ i ) {
		_areas[i]->hide();
	}

};

} } }
