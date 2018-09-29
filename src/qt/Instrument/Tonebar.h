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


};

}; }; };

