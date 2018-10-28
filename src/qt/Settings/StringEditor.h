/**
 * String editor
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Widget/BaseWidget.h>

#include <ui_StringEditor.h>

#include "StringEditArea.h"


using std::vector;


namespace Orza { namespace Steel { namespace Settings {

class StringEditor : public Orza::Steel::Widget::BaseWidget {

    Q_OBJECT;

	public:

		StringEditor();
		~StringEditor() {};

        void buildFrom( vector<float> );


    public slots:

        /**
         * Events
         */

        void handleAddClick();


	private:

		Ui_StringEditor _UI;

        vector<StringEditArea*> _areas;

        void handleClick();


};

} } }

