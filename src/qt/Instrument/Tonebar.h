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
		 * Template css
		 */

		static const char * TEMPLATE;


		/**
		 * Style sheet static for CSS
		 */

		static const char * STYLE_SHEET_TEMPLATE;

		Tonebar( QWidget * parent );

		Tonebar() {};
		~Tonebar() {};


		void setImage( const char * );


	protected:

		/**
		 * Mouse event watching for string control events
		 */


};

}; }; };

