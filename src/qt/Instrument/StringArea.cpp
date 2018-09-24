/**
 * String area clicking impl
 */
#include "StringArea.h"

#include <QStyleOption>

#include <iostream>

namespace Orza { namespace Steel { namespace Instrument {

/**
 * Event types
 */

const char * StringArea::EVENT_DOWN = "d";
const char * StringArea::EVENT_UP = "u";


/**
 * Template for CSS
 */

const char * StringArea::STYLE_SHEET_TEMPLATE = "\
	background-color: #%s;\n\
	border: 2px solid #888;\n\
	border-bottom: 1px solid #888;\n\
";


/**
 * Construct
 */

StringArea::StringArea( const char * color ) :
	_color( color )
{

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch( 0 );
	sizePolicy2.setVerticalStretch( 0 );
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	setActive( false );

	show();

};


void StringArea::setActive( bool flag ) {

	const char * color = ( flag )
		? "000000"
		: _color;

	char * css = formatStyleSheet( color );

	std::cout << css << "\n";

	setStyleSheet( css );

};

/**
 * Mouse event then push up
 */

void StringArea::mousePressEvent( QMouseEvent * event ) {

	_isMouseDown = true;

	dispatch( EVENT_DOWN, (void*) this );

};

void StringArea::mouseReleaseEvent( QMouseEvent * event ) {

	_isMouseDown = false;

	dispatch( EVENT_UP, (void*) this );

};

char * StringArea::formatStyleSheet( const char * color ) {

	char * css = (char*) malloc(
		( sizeof( color ) + sizeof( STYLE_SHEET_TEMPLATE ) )
		* sizeof( const char * )
	);


	sprintf( css, STYLE_SHEET_TEMPLATE, color );

	return css;

};

}; }; };
