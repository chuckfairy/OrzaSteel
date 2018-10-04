/**
 * String area clicking impl
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


class PedalWrap : public Orza::Steel::Widget::BaseWidget {

	public:

		PedalWrap();
		~PedalWrap() {};


		void createDisplay();


	private:

		vector<PedalArea*> _pedals;

};

} } }
