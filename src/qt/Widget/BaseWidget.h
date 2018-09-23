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

		BaseWidget() {};
		~BaseWidget() {};

		/**
		 * CSS painting
		 */

		void paintEvent( QPaintEvent * event ) {

			QStyleOption opt;
			opt.init(this);
			QPainter p(this);
			style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

			QWidget::paintEvent(event);

		}

};

} } }
