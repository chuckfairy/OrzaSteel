/**
 * String area clicking
 */
#pragma once

#include <string>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>
#include <Widget/BackgroundImage.h>


using std::string;

using Orza::Steel::Widget::BackgroundImage;


namespace Orza { namespace Steel { namespace Instrument {


class Tonebar : public Orza::Steel::Widget::BaseWidget, public Util::Dispatcher {

	Q_OBJECT;

	public:

		/**
		 * Template css
		 */

		static const char * DEFAULT_IMAGE;


		/**
		 * Style sheet static for CSS
		 */

		static const char * STYLE_SHEET_TEMPLATE;

		Tonebar( QWidget * parent );

		Tonebar() {};
		~Tonebar() {};


	public slots:

		/**
		 * Set tonebar image
		 */
		void setImage( const char * );


	signals:

		/**
		 * To change image on the right thread
		 */
		void emitSetImage( const char * );


	protected:

		/**
		 * Mouse event watching for string control events
		 */

	private:

		BackgroundImage * _img;

		bool _showLine = true;

		void createLine();

		string _srcString;

};

}; }; };

