/**
 * Layout
 */

#include "Layout.h"

namespace Orza { namespace Steel { namespace Settings {

/**
 * Construct
 */

Layout::Layout( Server * server ) :
	_Server( server ),
	_Patchbay( new Orza::Widget::Patchbay( server ) )
{

	_UI.setupUi( this );

	QFile styleFile( ":/Styles/DarkStyle.qss" );
	styleFile.open( QFile::ReadOnly );
	QString style( styleFile.readAll() );

	connect(
		_UI.close_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( hide() )
	);

	_UI.tab_effects_layout->addWidget( _Patchbay->getWidgetContainer() );

};

} } }
