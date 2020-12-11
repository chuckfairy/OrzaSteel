#include "BackgroundImage.h"
#include <iostream>

/**
 * construct
 */

namespace Orza { namespace Steel { namespace Widget {

BackgroundImage::BackgroundImage( const char * src, float opacity ) :
	_src( src ),
	_opacity( opacity )
{
	setAttribute(Qt::WA_TransparentForMouseEvents);

	//Emitting for src change
	connect(
		this,
		SIGNAL( emitSetSource(const char *) ),
		this,
		SLOT( setSource(const char *) )
	);
};

void BackgroundImage::paintEvent(QPaintEvent *p2)
{

	std::cout << "Loading image " << _src << "\n";
	QPixmap pixmap;
	pixmap.load( _src );

	QPainter paint(this);
	paint.setOpacity(_opacity);
	paint.drawPixmap(0, 0, pixmap.scaled( size() ) );
	QWidget::paintEvent(p2);

};

} } };
