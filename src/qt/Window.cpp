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

#include "Resource/Icons.h"

#include "Window.h"

using Orza::App::Resource::Icons;

namespace Orza { namespace App {


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
