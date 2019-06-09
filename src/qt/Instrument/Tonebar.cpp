/**
 * String area clicking
 */
#include "Tonebar.h"

#include <Widget/Line.h>
#include <Widget/BackgroundImage.h>


using Orza::Steel::Widget::Line;
using Orza::Steel::Widget::BackgroundImage;


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
		background: transparent;\
		"
	);

	setGeometry( 10, 0, 75, parentWidget()->height());

	BackgroundImage * img = new BackgroundImage(":/tonebars/malort.png");
	img->setGeometry( 0, 0, 75, 200 );
	img->setParent(this);


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

	Line * l = new Line();
	l->setParent(this);
	l->setGeometry(width() / 2, 0, 3, height());

};

} } }
