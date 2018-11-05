/**
 * String area clicking impl
 */
#include "PedalWrap.h"

#include "AreaData.h"


using std::vector;

using Orza::Steel::Audio::Pedal;


namespace Orza { namespace Steel { namespace Instrument {


PedalWrap::PedalWrap() {

	setupLayout();
	setMouseTracking( true );

	setStyleSheet(
		"\
		background: transparent;\
		"
	);

};


/**
 * Main creation
 */

void PedalWrap::createDisplay( vector<Pedal*> pedals ) {

	clearArea();

	int pl = pedals.size();

	for( int i = 0; i < pl; ++ i ) {

		Pedal * pedal = pedals[ i ];

		AreaData * data = new AreaData();
		data->label = pedal->label.c_str();

		PedalArea * area = new PedalArea( data );
		area->setMouseTracking( true );

		_layout->addWidget( area );

		_pedals.push_back( area );

	}

};


/**
 * Pedal active usage
 */

void PedalWrap::setPedalActive( uint8_t index, bool active ) {

	_pedals[ index ]->setActive( active );

};


/**
 * setup widget layout
 */

void PedalWrap::setupLayout() {

	_layout = new QHBoxLayout();
	_layout->setSpacing( 0 );
	_layout->setContentsMargins(0, 0, 0, 0);

	setLayout( _layout );

};


/**
 * Clear section and areas
 */

void PedalWrap::clearArea() {

	_pedals.clear();

	QLayoutItem * item;

	while( ( item = _layout->takeAt( 0 ) ) ) {

		if( item->widget() ) {

			delete item->widget();

		}

		delete item;

	}

}

} } }
