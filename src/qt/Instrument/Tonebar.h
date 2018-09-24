/**
 * String area clicking
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>


namespace Orza { namespace Steel { namespace Instrument {


class Tonebar : public Orza::Steel::Widget::BaseWidget, public Util::Dispatcher {

	public:

		/**
		 * Event types
		 */

		static const char * EVENT_MOVE;
		static const char * EVENT_UP;
		static const char * EVENT_DOWN;


		/**
		 * Style sheet static for CSS
		 */

		static const char * STYLE_SHEET_TEMPLATE;

		Tonebar( QWidget * parent );

		Tonebar() {};
		~Tonebar() {};


	protected:

		/**
		 * Mouse event watching for string control events
		 */


	private:

		/**
		 * Props
		 */

		bool _isMouseDown = false;

};

}; }; };

