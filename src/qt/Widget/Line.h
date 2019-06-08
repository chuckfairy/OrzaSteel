/**
 * Line
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QStyleOption>


namespace Orza { namespace Steel { namespace Widget {

class Line : public QWidget {
	public:
		explicit Line(QWidget *parent = nullptr) : QWidget(parent) {
			setAttribute(Qt::WA_NoSystemBackground);
			setAttribute(Qt::WA_TransparentForMouseEvents);
		}
	protected:
		void paintEvent(QPaintEvent *) override {
			QPainter(this).fillRect(rect(), {80, 80, 255, 128});
		}
};

}}};
