/**
 * String area clicking impl
 */
#include <iostream>

#include "StringArea.h"

#include <QStyleOption>
#include <QLabel>

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
	border-bottom: 1px solid #333;\n\
	border-left: 1px solid #333;\n\
";


/**
 * Construct
 */

StringArea::StringArea( AreaData * data ) :
	_data( data )
{

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch( 0 );
	sizePolicy2.setVerticalStretch( 0 );
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

    setAttribute( Qt::WA_AcceptTouchEvents, true );
	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	setActive( false );

	QLabel * label = new QLabel;
	label->setText( data->label );
	label->setParent( this );
	label->setStyleSheet("\
		color: #000;\
		border: none;\
		background: transparent;\
	");
	label->move(5, 5);

	//To ensure setActive will occur on Qt5 thread
	connect(
		this,
		SIGNAL( emitActive(bool) ),
		this,
		SLOT( setActive(bool) )
	);

	show();

};


void StringArea::setActive( bool flag ) {

	const char * color = ( flag )
		? "000000"
		: _data->color;

	char * css = formatStyleSheet( color );

	setStyleSheet( css );

	_isMouseDown = flag;

	dispatch( flag ? EVENT_DOWN : EVENT_UP, (void*) this );

};


/**
 * Mouse event then push up
 */

void StringArea::mousePressEvent( QMouseEvent * event ) {

	setActive( true );

};

void StringArea::mouseReleaseEvent( QMouseEvent * event ) {

	setActive( false );

};


/**
 * All event override
 * mainly for touch
 */

bool StringArea::event( QEvent *event ) {

	switch (event->type()) {
		case QEvent::TouchBegin:
			setActive( true );
			break;

		case QEvent::TouchEnd:
			setActive( false );
			break;

		default:
			return QWidget::event( event );
	}

	return true;

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
