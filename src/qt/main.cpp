/**
 * Start main qt window
 *
 */
#include <iostream>

#include <signal.h>
#include <QApplication>
#include "Window.h"

using namespace std;
using Orza::App::Window;

QApplication * app;

Window * win;


//Signal handler if from CLI

static void signal_handler( int ignored ) {

	win->goWindowed();
	app->closeAllWindows();
	app->quit();

};


//Main startup using MainWindow

int main( int argc, char **argv ) {

	// Qt app

	app = new QApplication( argc, argv );

	win = new Window( app );

	win->show();

	signal( SIGINT, signal_handler );
	signal( SIGTERM, signal_handler );

	return app->exec();

}
