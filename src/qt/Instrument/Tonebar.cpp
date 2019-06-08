/**
 * String area clicking
 */
#include "Tonebar.h"


namespace Orza { namespace Steel { namespace Instrument {


const char * Tonebar::TEMPLATE = "\
	border-image:url(\"%s\")  0 0 0 0 stretch stretch;\
	background: transparent;\
";

/**
 * Constructor
 */

Tonebar::Tonebar( QWidget * parent ) :
	BaseWidget( parent )
{
	QSizePolicy sizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	setSizePolicy( sizePolicy );

	setStyleSheet(
		"\
		border-image:url(\":/tonebars/malort.png\")  0 0 0 0 stretch stretch;\
		background: transparent;\
		"
	);

	setGeometry( 10, 0, 75, 200 );

	if(_showLine) {
		createLine();
	}

	raise();

	show();

};


/**
 * Set image
 */

void Tonebar::setImage( const char * img ) {

};


/**
 * Create line helper
 */

void Tonebar::createLine() {



};

} } }
