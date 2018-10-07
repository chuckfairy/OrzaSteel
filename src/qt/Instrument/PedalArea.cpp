/**
 * Pedal area creator
 */
#include <QLabel>

#include "PedalArea.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * CSS template
 */

const char * PedalArea::TEMPLATE = "\
background: #%s;\
border-radius: 5px 5px 0 0;\
color: #000;\
border: 1px solid #000;\
";


/**
 * Construct setup
 */

PedalArea::PedalArea( AreaData * data ) :
	_data( data ),
	_label( new QLabel )
{

	_label->setParent( this );
	_label->setText( data->label );

	setActive( false );

	QSizePolicy sizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );

	setSizePolicy( sizePolicy );

};


/**
 * Active
 */

void PedalArea::setActive( bool flag ) {

	const char * color = ( flag )
		? "AAA"
		: "CCC";

	char * css = (char*) malloc(
		( sizeof( color ) + sizeof( TEMPLATE ) )
		* sizeof( const char * )
	);

	sprintf( css, TEMPLATE, color );

	_label->setStyleSheet( css );

};

} } }
