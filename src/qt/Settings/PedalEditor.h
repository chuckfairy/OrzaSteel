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

#include <Widget/TreeNode.h>

#include "PedalEditArea.h"

#include "Events/UpdateEvent.h"


using Orza::Steel::Audio::Pedal;
using Orza::Widget::TreeNode;


/**
 * Forwarding
 */

namespace Orza { namespace Steel {

class Window;

} }

using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Settings {


class PedalEditor : public TreeNode {

    Q_OBJECT;

	public:

		PedalEditor( Window * );
		~PedalEditor() {};


		/**
		 * API
		 */

		void buildFrom( vector<Pedal*> );

		void remove( TreeNode * );

		void addNode( TreeNode * );

		void handleNodeUpdate( TreeNode * );


	public slots:

		/**
		 * Events
		 */

		void handleAddClick();


	protected:

		void afterRemove();


	private:

		Ui_PedalEditor _UI;

		Window * _win;

		vector<PedalEditArea*> _areas;

		bool _building = false;


		/**
		 * Internal
		 */

		void updateInstrument();


};

} } }
