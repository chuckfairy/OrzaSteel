#include "BackgroundImage.h"

/**
 * construct
 */

namespace Orza { namespace Steel { namespace Widget {

BackgroundImage::BackgroundImage( const char * src, float opacity ) :
	_src( src ),
	_opacity( opacity )
{
	setAttribute(Qt::WA_TransparentForMouseEvents);
};

void BackgroundImage::paintEvent(QPaintEvent *p2)
{
	QPixmap pixmap;
	pixmap.load( _src );

	QPainter paint(this);
	paint.setOpacity(_opacity);
	paint.drawPixmap(0, 0, pixmap.scaled( size() ) );
	QWidget::paintEvent(p2);
};

} } };
