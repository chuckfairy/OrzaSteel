/**
 * String area clicking
 */
#include "Tonebar.h"

#include <QGraphicsOpacityEffect>

#include <Widget/Line.h>


using Orza::Steel::Widget::Line;
using Orza::Steel::Widget::BackgroundImage;


namespace Orza { namespace Steel { namespace Instrument {


const char * Tonebar::DEFAULT_IMAGE = ":/tonebars/malort.png";

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

	setImage(DEFAULT_IMAGE);

	if(_showLine) {
		createLine();
	}

	connect(
		this,
		SIGNAL( emitSetImage(const char *) ),
		this,
		SLOT( setImage(const char *) )
	);

	raise();

	show();

};


/**
 * Set image
 */

void Tonebar::setImage( const char * src ) {

	_srcString = string(src);

	if(_img == nullptr) {
		_img = new BackgroundImage(_srcString.c_str());
		_img->setGeometry( 0, 0, 75, 200 );
		_img->setParent(this);

		//opacity
		QGraphicsOpacityEffect * op = new QGraphicsOpacityEffect();
		op->setOpacity(1); //0 to 1 will cause the fade effect to kick in
		_img->setGraphicsEffect(op);
		_img->setAutoFillBackground(true);
	}

	_img->setSource(_srcString.c_str());

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
