/**
 * String area clicking impl
 */
#include <stdexcept>

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
		"
	);

	//Thread safe
	connect(
		this,
		SIGNAL( emitPedalActive( int, bool ) ),
		this,
		SLOT( setPedalActive( int, bool ) )
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

		PedalArea * area = _areas[i];

		AreaData * data = area->getData();
		data->label = pedal->label.c_str();

		area->build();
		area->setMouseTracking( true );
		area->show();

	}

};


/**
 * Pedal active usage
 */

void PedalWrap::setPedalActive( int index, bool active ) {

	_areas[ index ]->setActive( active );

};


/**
 * setup widget layout
 */

void PedalWrap::setupLayout() {

	_layout = new QHBoxLayout();
	_layout->setSpacing( 2 );
	_layout->setContentsMargins(0, 0, 0, 0);

	setLayout( _layout );

};


/**
 * Clear section and areas
 */

void PedalWrap::clearArea() {

	if(_areas.size() == 0) {
		//Max number of areas ever?
		int pedalNumbers = 12 * 4;

		for(int i = 0; i < pedalNumbers; ++i) {
			AreaData * data = new AreaData();

			PedalArea * area = new PedalArea( data );

			_layout->addWidget( area );

			_areas.push_back(area);
		}
	}

	//@TODO figure out why we need
	//Will not display without it
	_layout->addWidget( new QLabel() );

	int al = _areas.size();
	for( int i = 0; i < al; ++ i ) {
		_areas[i]->hide();
	}

}

} } }
