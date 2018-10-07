/**
 * Pedal area creator
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QLabel>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include "AreaData.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {

class PedalArea : public Orza::Steel::Widget::BaseWidget, public Util::Dispatcher {

	public:

		static const char * TEMPLATE;

		PedalArea( AreaData * );
		~PedalArea() {};


		/**
		 * Active setting
		 */

		void setActive( bool );


	private:

		AreaData * _data;

		QLabel * _label;

};

} } }
