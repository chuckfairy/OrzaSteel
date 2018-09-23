/**
 * String area clicking
 */
#include "Tonebar.h"


namespace Orza { namespace Steel { namespace Instrument {


Tonebar::Tonebar() {

	setStyleSheet(
		"\
		background-image:url(\":/tonebars/pbr.png\"); background-position: center;\
		position: absolute;\
		top: 0;\
		left: 0;\
		width: 200px;\
		height: 200px;\
		\
		"
	);

};

}; }; };

