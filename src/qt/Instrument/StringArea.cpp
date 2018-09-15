/**
 * String area clicking impl
 */
#include "StringArea.h"


namespace Orza { namespace Steel { namespace Instrument {


/**
 * Construct
 */

StringArea::StringArea( const char * color ) :
	_color( color )
{

	QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
	sizePolicy2.setHorizontalStretch(0);
	sizePolicy2.setVerticalStretch(0);
	sizePolicy2.setHeightForWidth( sizePolicy().hasHeightForWidth() );

	setSizePolicy(sizePolicy2);
	setMinimumSize(QSize(250, 0));

	// set background color

	QPalette pal = palette();

	pal.setColor(QPalette::Background, Qt::red);
	setAutoFillBackground(true);
	setPalette(pal);
	show();

	//setStyleSheet(
		//"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	//);


};

}; }; };
