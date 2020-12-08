#pragma once

#include <QtCore>
#include <QtGui>
#include <QWidget>

namespace Orza { namespace Steel { namespace Widget {

class BackgroundImage : public QWidget {

	Q_OBJECT;

	public:

		BackgroundImage(QWidget *parent = 0) {};

		BackgroundImage( const char * src, float opacity = 1.0 );

		~BackgroundImage() {};

		void setOpacity( float opacity ) {
			_opacity = opacity;
		};


	public slots:

		void setSource( const char * src ) {
			_src = src;
		};


	signals:

		void emitSetSource( const char * );

	private:

		const char * _src;
		float _opacity;

	protected:

		void paintEvent(QPaintEvent *p2);

};

} } };
