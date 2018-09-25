/**
 * Fret area
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>


namespace Orza { namespace Steel { namespace Instrument {


class FretArea : public Orza::Steel::Widget::BaseWidget, public Util::Dispatcher {

	public:

		/**
		 * Event types
		 */

		static const char * EVENT_DOWN;
		static const char * EVENT_UP;


		/**
		 * Style sheet static for CSS
		 */

		static const char * STYLE_SHEET_TEMPLATE;

		FretArea( const char * color );
		~FretArea() {};


	private:

		/**
		 * Props
		 */

		const char * _color;

        char * formatStyleSheet( const char * color );

};

} } }
