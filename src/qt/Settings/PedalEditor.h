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

#include <Audio/Pedal.h>

#include "PedalEditArea.h"


using Orza::Steel::Audio::Pedal;


namespace Orza { namespace Steel { namespace Settings {

class PedalEditor : public Orza::Steel::Widget::BaseWidget {

    Q_OBJECT;

	public:

		PedalEditor();
		~PedalEditor() {};


        void buildFrom( vector<Pedal*> );


    public slots:

        /**
         * Events
         */

        void handleAddClick();


	private:

		Ui_PedalEditor _UI;

        vector<PedalEditArea*> _areas;

        void handleClick();


};

} } }
