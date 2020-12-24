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
border-radius: 5px 5px 5px 5px;\
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

	setActive( false );

	//setGeometry(0, 0, 300, 100);

	QSizePolicy sizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );

	setSizePolicy( sizePolicy );

	//To ensure setActive will occur on Qt5 thread
	connect(
		this,
		SIGNAL( emitActive(bool) ),
		this,
		SLOT( setActive(bool) )
	);

};

void PedalArea::build() {

	_label->setParent( this );
	_label->setText( _data->label );

};


/**
 * Active
 */

void PedalArea::setActive( bool flag ) {

	const char * color = ( flag )
		? "AAA"
		: "DDD";

	char * css = (char*) malloc(
		( sizeof( color ) + sizeof( TEMPLATE ) + 20 )
		* sizeof( const char * )
	);

	sprintf( css, TEMPLATE, color );

	_label->setStyleSheet( css );

};

AreaData * PedalArea::getData() {

	return _data;

};

} } }
