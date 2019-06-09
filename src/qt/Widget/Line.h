/**
 * Line
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QStyleOption>
#include <QColor>


namespace Orza { namespace Steel { namespace Widget {

class Line : public QWidget {

	public:

		/**
		 * Construct and basic helpers
		 */
		Line() {
			setAttribute(Qt::WA_TransparentForMouseEvents);
		}

		Line(QColor color) :
			_color(color)
		{
			setAttribute(Qt::WA_TransparentForMouseEvents);
		}

		void setColor(QColor color) {
			_color = color;
		}


	protected:
		/**
		 * Main paint
		 */
		void paintEvent(QPaintEvent *) override {
			//Setup painter
			QPainter painter(this);
			painter.fillRect(rect(), _color);
			painter.setRenderHint(QPainter::Antialiasing);
		}

	private:
		QColor _color = Qt::red;

};

}}};
