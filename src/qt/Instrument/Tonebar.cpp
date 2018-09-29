/**
 * String area clicking
 */
#include "Tonebar.h"


namespace Orza { namespace Steel { namespace Instrument {


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
		border-image:url(\":/tonebars/pbr.png\")  0 0 0 0 stretch stretch;\
		background: transparent;\
		"
	);

	setGeometry( 10, 0, 70, 200 );

	raise();

	show();

};

} } }
