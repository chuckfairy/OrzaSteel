/**
 * String editor
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Audio/Pedal.h>

#include <Widget/BaseWidget.h>

#include <ui_PedalEditArea.h>

#include <Widget/TreeNode.h>


using std::vector;

using Orza::Steel::Audio::Pedal;
using Orza::Widget::TreeNode;


namespace Orza { namespace Steel { namespace Settings {

class PedalEditArea : public TreeNode {

    Q_OBJECT;

	public:

        static const char * NODE_UPDATE_EVENT;

		PedalEditArea();
		~PedalEditArea() {};


        /**
         * Values
         */

        vector<int> getStringNums();

        void setLabel( const char * );

        void setModifier( int );

        void setStrings( vector<uint8_t> );


        /**
         * Getters
         */

        Pedal * getAsPedal();


    public slots:

        void sendUpdate();


	private:

        Pedal _ped;

		Ui_PedalEditArea _UI;


};

} } }

