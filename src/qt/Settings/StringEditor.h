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

#include <Widget/TreeNode.h>


using std::vector;

using Orza::Widget::TreeNode;


/**
 * Forwarding
 */

namespace Orza { namespace Steel {

class Window;

} }


using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Settings {

class StringEditor : public TreeNode {

    Q_OBJECT;

	public:

		StringEditor( Window * );
		~StringEditor() {};

        void buildFrom( vector<float> );


        /**
         * Handlers
         */

        void remove( TreeNode * );

        void addNode( TreeNode * );


    public slots:

        /**
         * Events
         */

        void handleAddClick();


    protected:

        void afterRemove();


	private:

		Ui_StringEditor _UI;

		Window * _win;


        /**
         * Internal
         */

        void updateInstrument();


};

} } }

