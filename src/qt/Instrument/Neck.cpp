/**
 * Neck impl
 */
#include "Neck.h"

namespace Orza { namespace Steel { namespace Instrument {

/**
 * constructor
 */

Neck::Neck() {

	_Bar = new Tonebar( this );

	_positions.push_back( 0 );

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

vector<uint8_t> Neck::getPositions() {

	vector<uint8_t> out;

	return out;

};


/**
 * Mouse move and tonebar setting
 */

void Neck::mouseMoveEvent( QMouseEvent * event ) {

	std::cout << "Mouse move : " << event->x() << " " << event->y() << "\n";

	_positions[ 0 ] = ( event->y() / width() ) * 100;

	_Bar->move( event->x() - ( _Bar->width() / 2 ), 0 );


};

} } }
