/**
 * String editor
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include <ui_StringEditor.h>


namespace Orza { namespace Steel { namespace Settings {

class StringEditor : public Orza::Steel::Widget::BaseWidget {

	public:

		StringEditor();
		~StringEditor() {};


	private:

		Ui_StringEditor _UI;


};

} } }

