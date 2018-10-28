/**
 * String editor
 */
#pragma once

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include <ui_StringEditArea.h>


namespace Orza { namespace Steel { namespace Settings {

class StringEditArea : public Orza::Steel::Widget::BaseWidget {

	public:

		StringEditArea();
		~StringEditArea() {};


        /**
         * Values
         */

        int getStringNote();

        void setStringNote( float );


	private:

		Ui_StringEditArea _UI;


};

} } }

