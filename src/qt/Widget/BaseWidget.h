/**
 * Base widget for module usages
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QStyleOption>


namespace Orza { namespace Steel { namespace Widget {


class BaseWidget : public QFrame {

	protected:

		BaseWidget( QWidget * parent ) : QFrame( parent ) {};

		BaseWidget() {};
		~BaseWidget() {};


		/**
		 * CSS painting
		 */

		void paintEvent( QPaintEvent * event ) {

			setAttribute(Qt::WA_TranslucentBackground);

			QStyleOption opt;
			opt.init(this);
			_painter = new QPainter(this);
            //_painter->setOpacity( 0.5 );
			style()->drawPrimitive(QStyle::PE_Widget, &opt, _painter, this);

			//QWidget::paintEvent(event);

		};

        QPainter * _painter;

};

} } }
