/**
 * Pedal area creator
 */
#include <QLabel>

#include "PedalArea.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Construct setup
 */

PedalArea::PedalArea( AreaData * data ) :
	_data( data )
{

	QLabel * label = new QLabel();
	label->setParent( this );
	label->setText( data->label );

	setStyleSheet(
		"\
		"
	);

};

} } }
