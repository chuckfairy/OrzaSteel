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
	_Patchbay( new Orza::Widget::Patchbay( server ) ),
	_PedalEditor( new PedalEditor() ),
	_StringEditor( new StringEditor() )
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

	_UI.tab_pedals_layout->addWidget( _PedalEditor );
	_UI.tab_strings_layout->addWidget( _StringEditor );

};

} } }
