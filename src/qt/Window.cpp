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


using std::vector;

using Orza::App::Resource::Icons;
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


	//Icons setup

	Icons::setResource( app );


	//Icon

	QIcon icon(":icon.png");
	setWindowIcon( icon );


	//Setup and apply stylesheet

	QFile styleFile( ":/Styles/DarkStyle.qss" );
	styleFile.open( QFile::ReadOnly );
	QString style( styleFile.readAll() );

	UI.centralWidget->setStyleSheet( style );

	//Background image

	UI.neck_content->setStyleSheet(
		"border-image:url(\":/necks/basic-wood.png\") 0 0 0 0 stretch stretch;"
	);


	//Jack Startup

	_Server = new Jack::Server();

	_Server->start();
	_Server->connectDefault();


	//Module messin

	Instrument::Module * mod = new Instrument::Module( this );

	addModule( mod );


	Util::Event * e = new JackProcess<Window>( this );
	_Server->on( Jack::Server::UPDATE_EVENT, e );



	//Main start

	_Server->run();

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
