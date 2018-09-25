/**
 * String area clicking impl
 */
#include <QStyleOption>

#include "FretArea.h"


namespace Orza { namespace Steel { namespace Instrument {


/**
 * Template for CSS
 */

const char * FretArea::STYLE_SHEET_TEMPLATE = "\
	background-color: #%s;\n\
	border: 2px solid #888;\n\
	border-bottom: 1px solid #888;\n\
";


/**
 * Construct
 */

FretArea::FretArea( const char * color ) :
	_color( color )
{

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch( 0 );
	sizePolicy2.setVerticalStretch( 0 );
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	char * css = formatStyleSheet( color );

	std::cout << css << "\n";

	setStyleSheet( css );

	show();

};


/**
 * CSS
 */

char * FretArea::formatStyleSheet( const char * color ) {

	char * css = (char*) malloc(
		( sizeof( color ) + sizeof( STYLE_SHEET_TEMPLATE ) )
		* sizeof( const char * )
	);

	sprintf( css, STYLE_SHEET_TEMPLATE, color );

	return css;

};

}; }; };
