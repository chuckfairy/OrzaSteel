/**
 * Layout
 */

#include "Layout.h"

namespace Orza { namespace Steel { namespace Settings {

/**
 * Construct
 */

Layout::Layout() {

    _UI.setupUi( this );

	QFile styleFile( ":/Styles/DarkStyle.qss" );
	styleFile.open( QFile::ReadOnly );
	QString style( styleFile.readAll() );

};



} } }
