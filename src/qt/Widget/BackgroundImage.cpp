#include "BackgroundImage.h"

/**
 * construct
 */

namespace Orza { namespace Steel { namespace Widget {

BackgroundImage::BackgroundImage( const char * src ) :
	_src( src )
{
	setAttribute(Qt::WA_TransparentForMouseEvents);
};

void BackgroundImage::paintEvent(QPaintEvent *p2)
{
	QPixmap pixmap;
	pixmap.load( _src );

	QPainter paint(this);
	paint.drawPixmap(0, 0, pixmap.scaled( size() ) );
	QWidget::paintEvent(p2);
};

} } };
