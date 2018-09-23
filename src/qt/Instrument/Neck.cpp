/**
 * Neck impl
 */
#include "Neck.h"

namespace Orza { namespace Steel { namespace Instrument {

/**
 * constructor
 */

Neck::Neck() :
	_Bar( new Tonebar )
{

	//setupLayout();

	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	setSizePolicy(sizePolicy);

	setStyleSheet(
		"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	);

	show();

	//_layout->addWidget( _Bar );

};


/**
 * Positions getter
 */

vector<uint8_t> Neck::getPositions() {

}


/**
 * setup widget layout
 */

void Neck::setupLayout() {

	_layout = new QVBoxLayout();
	_layout->setSpacing( 0 );
	_layout->setContentsMargins(0, 0, 0, 0);

	setLayout( _layout );

};

} } }
