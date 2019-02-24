/**
 * Layout toplevel settings
 */
#pragma once

#include <liborza-qt/src/Settings/Layout.h>

#include <Widget/BaseWidget.h>

#include <Widget/Patchbay.h>

#include <Jack/Server.h>

#include <ui_Settings.h>

#include "PedalEditor.h"
#include "StringEditor.h"


using Jack::Server;


/**
 * Forwarding
 */

namespace Orza { namespace Steel {

class Window;

} }


namespace Orza { namespace Steel { namespace Settings {


using Orza::Steel::Window;


/**
 * Main class
 */

class Layout : public Orza::Steel::Widget::BaseWidget {

	public:

		Layout( Window * );


		/**
		 * getters
		 */

		PedalEditor * getPedalEditor() {

			return _PedalEditor;

		};

		StringEditor * getStringEditor() {

			return _StringEditor;

		};


	private:

		/**
		 * Props
		 */

		Ui_Settings _UI;

		Window * _win;

		Server * _Server;

		Orza::Settings::Layout * _generalLayout;


		/**
		 * Tabs
		 */

		Orza::Widget::Patchbay * _Patchbay;

		PedalEditor * _PedalEditor;

		StringEditor * _StringEditor;


};

} } }
