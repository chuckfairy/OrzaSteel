/**
 * window class
 *
 */
#pragma once

#include <QtCore>
#include <Qt>

#include <vector>

#include <Jack/Server.h>

#include "ui_Window.h"

#include "Settings/Layout.h"


using std::vector;


namespace Orza { namespace Steel {

/**
 * Forwarding
 */

class BaseModule;


/**
 * class
 */

class Window : public QMainWindow {

	Q_OBJECT;

	public:

		// override the constructor

		explicit Window(QApplication *, QWidget * parent = 0, ::Qt::WindowFlags flags = 0);
		~Window() {};


		/**
		 * Qt UI
		 */

		Ui_Window * getUI() {

			return &UI;

		};

		Jack::Server * getServer() {

			return _Server;

		};


		/**
		 * Window actions
		 */

		void goFullscreen();

		void goWindowed();


		/**
		 * Jack processor
		 */

		void process( jack_nframes_t );


		/**
		 * add module
		 */

		void addModule( BaseModule * );


	protected slots:

		/**
		 * settings
		 */

		void toggleSettings();


	protected:

		/**
		 * Override send to all mods
		 */

		void keyPressEvent( QKeyEvent * event );

		void keyReleaseEvent( QKeyEvent * event );

		void resizeEvent( QResizeEvent *event );

	private:

		/**
		 * Qt Window UI
		 */

		Ui_Window UI;

		/**
		 * Main audio server
		 */

		Jack::Server * _Server;


		/**
		 * Modules
		 */

		vector<BaseModule*> _modules;

		Settings::Layout * _Settings;


};

} }
