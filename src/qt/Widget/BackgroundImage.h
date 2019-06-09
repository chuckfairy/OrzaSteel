#pragma once

#include <QtCore>
#include <QtGui>
#include <QWidget>

namespace Orza { namespace Steel { namespace Widget {

class BackgroundImage : public QWidget {

	Q_OBJECT;

	public:

		BackgroundImage(QWidget *parent = 0) {};

		BackgroundImage( const char * src );

		~BackgroundImage() {};

	private:

		const char * _src;

	protected:

		void paintEvent(QPaintEvent *p2);

};

} } };
