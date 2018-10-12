/**
 * Pedal editor
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include <ui_PedalEditor.h>


namespace Orza { namespace Steel { namespace Settings {

class PedalEditor : public Orza::Steel::Widget::BaseWidget {

	public:

		PedalEditor();
		~PedalEditor() {};


	private:

		Ui_PedalEditor _UI;


};

} } }
