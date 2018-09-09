#include "BackgroundImage.h"

/**
 * construct
 */

BackgroundImage::BackgroundImage( const char * src ) :
	_src( src )
{
};

void BackgroundImage::paintEvent(QPaintEvent *p2)
{
	QPixmap pixmap;
	pixmap.load( _src );

	QPainter paint(this);
	paint.drawPixmap(0, 0, pixmap.scaled( size() ) );
	QWidget::paintEvent(p2);
};
