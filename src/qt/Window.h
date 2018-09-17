/**
 * window class
 *
 */
#pragma once

#include <QtCore>
#include <Qt>

#include <Jack/Server.h>

#include "ui_Window.h"


namespace Orza { namespace Steel {

/**
 *	class
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


	private:

		/**
		 * Qt Window UI
		 */

		Ui_Window UI;

		/**
		 * Main audio server
		 */

		Jack::Server * _Server;

};

} }
