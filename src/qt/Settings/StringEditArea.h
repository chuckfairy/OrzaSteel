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

#include <Widget/TreeNode.h>


using Orza::Widget::TreeNode;


namespace Orza { namespace Steel { namespace Settings {


class StringEditArea : public TreeNode {

    Q_OBJECT;

	public:

		StringEditArea();
		~StringEditArea() {};


        /**
         * Values
         */

        float getStringNote();

        void setStringNote( float );


	private:

		Ui_StringEditArea _UI;


};

} } }

