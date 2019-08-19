/**
 * Layout
 */
#include <Window.h>

#include <Instrument/Module.h>

#include "Layout.h"


using Orza::Steel::Instrument::Module;


namespace Orza { namespace Steel { namespace Settings {

/**
 * Construct
 */

Layout::Layout( Window * win ) :
    _win( win ),
	_Server( win->getServer() ),
	_Patchbay( new Orza::Widget::Patchbay( win->getServer() ) ),
	_PedalEditor( new PedalEditor( win ) ),
	_StringEditor( new StringEditor( win ) ),
	_ControlEditor( new Orza::MidiControl::Control( win->getServer() ) ),
	_generalSettings( new Orza::Settings::Layout( win->getServer() ) )
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

	//Add editors and Patchbay
	_UI.tab_effects_layout->addWidget( _Patchbay->getWidgetContainer() );
	_UI.tab_pedals_layout->addWidget( _PedalEditor );
	_UI.tab_strings_layout->addWidget( _StringEditor );
	_UI.tab_general_layout->addWidget( _generalSettings );
	_UI.tab_control_layout->addWidget( _ControlEditor->getWidget() );


	//Build string and pedal editor from current setup
	Module * insta = (Module*) _win->getModules()[0];

	_StringEditor->buildFrom( *(insta->getInstrument()->getStrings()) );
	_PedalEditor->buildFrom( *(insta->getInstrument()->getPedals()) );

};

} } }
