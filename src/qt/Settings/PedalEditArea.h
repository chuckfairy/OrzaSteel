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

#include <ui_PedalEditArea.h>


using std::vector;


namespace Orza { namespace Steel { namespace Settings {

class PedalEditArea : public Orza::Steel::Widget::BaseWidget {

	public:

		PedalEditArea();
		~PedalEditArea() {};


        /**
         * Values
         */

        vector<int> getStringNums();

        void setLabel( const char * );

        void setModifier( int );

        void setStrings( vector<uint8_t> );


	private:

		Ui_PedalEditArea _UI;


};

} } }

