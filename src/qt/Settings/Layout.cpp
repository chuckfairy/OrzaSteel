/**
 * Layout
 */
#include <Window.h>

#include <Instrument/Module.h>
#include <Audio/StringInstrument.h>

#include "Layout.h"

#include "InstrumentPresetWriter.h"
#include "InstrumentPresetLoader.h"


using Orza::Steel::Instrument::Module;
using Orza::Steel::Audio::StringInstrument;


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
	_ControlEditor( new Orza::MidiControl::Control( win->getServer() ) )
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
	_UI.tab_control_layout->addWidget( _ControlEditor->getWidget() );


	//Build string and pedal editor from current setup
	Module * insta = (Module*) _win->getModules()[0];
	StringInstrument * instrument = insta->getInstrument();

	_StringEditor->buildFrom( *(instrument->getStrings()) );
	_PedalEditor->buildFrom( *(instrument->getPedals()) );

	//General Settings setup
	InstrumentPresetWriter * writer = new InstrumentPresetWriter(instrument);
	InstrumentPresetLoader * loader = new InstrumentPresetLoader(
		_Server,
		instrument,
		_StringEditor,
		_PedalEditor,
		_Patchbay
	);

	_generalSettings = new Orza::Settings::Layout( win->getServer(), writer, loader);

	_UI.tab_general_layout->addWidget( _generalSettings );

};

} } }
