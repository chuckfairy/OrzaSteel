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
			setupLineSettings();
		}

		Line(QColor color) :
			_color(color)
		{
			setupLineSettings();
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

		void setupLineSettings() {
			setAttribute(Qt::WA_TransparentForMouseEvents);
		}

};

}}};
