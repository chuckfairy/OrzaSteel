/**
 * String area clicking impl
 */
#pragma once

#include <vector>

#include <Audio/Pedal.h>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include <QHBoxLayout>

#include "PedalArea.h"


using std::vector;

using Orza::Steel::Audio::Pedal;


namespace Orza { namespace Steel { namespace Instrument {


class PedalWrap : public Orza::Steel::Widget::BaseWidget {

	Q_OBJECT;

	public:

		PedalWrap();
		~PedalWrap() {};


		/**
		 * Main create of pedals
		 */

		void createDisplay( vector<Pedal*> );


	public slots:

		void setPedalActive( int index, bool active );


	signals:

		void emitPedalActive( int index, bool active );


	private:

		/**
		 * props
		 */

		vector<PedalArea*> _pedals;

		QHBoxLayout * _layout;


		/**
		 * internals
		 */

		void setupLayout();

		void clearArea();

};

} } }
