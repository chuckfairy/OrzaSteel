/**
 * Outer window
 *
 */
#include <iostream>

#include <QHBoxLayout>
#include <QFile>
#include <QTimer>
#include <QIcon>
#include <QDesktopWidget>

#include <Event/JackProcess.h>

#include "Window.h"

#include "Module/BaseModule.h"
#include "Resource/Icons.h"
#include "Instrument/Module.h"

#include "Settings/Layout.h"


using std::vector;

using Orza::Resource::Icons;
using Orza::Steel::Event::JackProcess;


namespace Orza { namespace Steel {


/**
 * Window construct
 *
 * @Override
 */

Window::Window( QApplication * app, QWidget * parent, Qt::WindowFlags flags ) :
	QMainWindow( parent, 0 )
{
	//QT ui from creator

	UI.setupUi( this );

	setWindowTitle( "OrzaSteel" );
    setAttribute( Qt::WA_AcceptTouchEvents, true );


	//Icons setup

	Icons::setResource( app );

	Orza::PluginSearch::LoadedPlugins::load();


	//Icon

	QIcon icon(":icon.png");
	setWindowIcon( icon );


	//Setup and apply stylesheet

	QFile styleFile( ":/Styles/DarkStyle.qss" );
	styleFile.open( QFile::ReadOnly );
	QString style( styleFile.readAll() );

	UI.centralWidget->setStyleSheet( style );


	//Jack Startup

	_Server = new Jack::Server();

	_Server->start();
	_Server->connectDefault();


	//Module messin

	Instrument::Module * mod = new Instrument::Module( this );

	addModule( mod );


	_Settings = new Settings::Layout( this );


	Util::Event * e = new JackProcess<Window>( this );
	_Server->on( Jack::Server::UPDATE_EVENT, e );



	//Main start

	_Server->run();


	//Sizing

	_Settings->setParent( UI.centralWidget );
	_Settings->setGeometry( 0, 0, width(), height() );
	_Settings->move(0, 0);
	_Settings->raise();
	_Settings->hide();


	//Events

	connect(
		UI.settings_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( toggleSettings() )
	);

	connect(
		UI.effects_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( toggleSettings() )
	);

};


/**
 * Jack processing
 */

void Window::process( jack_nframes_t nframes ) {

	for( int i = 0; i < _modules.size(); ++ i ) {

		_modules[ i ]->process( nframes );

	}

};


/**
 * Show settings over App
 */

void Window::toggleSettings() {

	( _Settings->isVisible() )
		? _Settings->hide()
		: _Settings->show();

};


/**
 * Add module helper
 */

void Window::addModule( BaseModule * mod ) {

	_modules.push_back( mod );

};


/**
 * Key press handler for modules
 */

void Window::keyPressEvent( QKeyEvent * event ) {

	if( event->isAutoRepeat() ) {

		return;

	}


	//Loop mods

	for( int i = 0; i < _modules.size(); ++ i ) {

		_modules[ i ]->handleKeyEvent( event );

	}

};

void Window::keyReleaseEvent( QKeyEvent * event ) {

	keyPressEvent( event );

};


/**
 * Resize handling
 */

void Window::resizeEvent( QResizeEvent * event ) {

    QMainWindow::resizeEvent(event);

	for( int i = 0; i < _modules.size(); ++ i ) {

		_modules[ i ]->handleResize( event );

	}

    _Settings->setGeometry( 0, 0, width(), height() );

};


/**
 * Window actions
 */

void Window::goFullscreen() {

	setWindowFlags( Qt::CustomizeWindowHint );
	setWindowFlags( Qt::FramelessWindowHint );

	showFullScreen();

};

void Window::goWindowed() {

	Qt::WindowFlags flag = windowFlags();
	flag = flag & (~Qt::CustomizeWindowHint) & (~Qt::FramelessWindowHint);

	setWindowFlags( flag );

	show();

	showNormal();

};

} }
