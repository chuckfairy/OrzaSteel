/**
 * String area clicking
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>


namespace Orza { namespace Steel { namespace Instrument {


class StringArea : public QWidget, public Util::Dispatcher {

	Q_OBJECT;

	public:

		/**
		 * Event types
		 */

		static const char * EVENT_DOWN;
		static const char * EVENT_UP;
		static const char * EVENT_CLICK;
		static const char * EVENT_PAUSE;


		/**
		 * Style sheet static for CSS
		 */

		static const char * STYLE_SHEET_TEMPLATE;

		StringArea( const char * color );
		~StringArea() {};


	protected:

		/**
		 * Mouse event watching for string control events
		 */

		void mousePressEvent( QMouseEvent * );

		void mouseReleaseEvent( QMouseEvent * );


		/**
		 * CSS painting
		 */

		void paintEvent( QPaintEvent * );


	private:

		/**
		 * Props
		 */

		const char * _color;

		bool _isMouseDown = false;

};

}; }; };
