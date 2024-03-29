/**
 * String area clicking impl
 */
#include <QStyleOption>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include "FretArea.h"


namespace Orza { namespace Steel { namespace Instrument {


/**
 * Template for CSS
 */

const char * FretArea::STYLE_SHEET_TEMPLATE = "\
	background-color: #%s;\
	border-left: 1px solid #000000;\n\
";


/**
 * Construct
 */

FretArea::FretArea( AreaData * data ) :
	_data( data )
{

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch( 0 );
	sizePolicy2.setVerticalStretch( 0 );
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	show();

};


void FretArea::render() {

	char * css = formatStyleSheet( _data->color );


	setStyleSheet( css );

	QLabel * label = new QLabel(this);
	label->setText( _data->label );
	label->move( 5, 15 );
	label->setStyleSheet(
		"color: #000000; border-left: none;"
	);

};


/**
 * Area data grab
 */

AreaData * FretArea::getData() {

	return _data;

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
