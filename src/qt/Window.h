/**
 * window class
 *
 */
#pragma once

#include <QtCore>
#include <Qt>

#include "ui_Window.h"


namespace Orza { namespace App {

/**
 *	class
 */

class Window : public QMainWindow {

	Q_OBJECT;

	public:

		// override the constructor

		explicit Window(QApplication *, QWidget * parent = 0, ::Qt::WindowFlags flags = 0);


		/**
		 * Qt UI
		 */

		Ui_Window * getUI() {

			return &UI;

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

};

} }
