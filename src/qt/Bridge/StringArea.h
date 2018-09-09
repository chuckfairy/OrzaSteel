/**
 * String area clicking
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

namespace Orza { namespace Steel { namespace Bridge {

class StringArea : public QWidget {

	Q_OBJECT;

	public:

		StringArea( const char * color );

	private:

		const char * _color;

};

}; }; };
