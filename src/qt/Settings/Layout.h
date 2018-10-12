/**
 * Layout toplevel settings
 */
#pragma once

#include <Widget/BaseWidget.h>

#include <Widget/Patchbay.h>

#include <Jack/Server.h>

#include <ui_Settings.h>

#include "PedalEditor.h"
#include "StringEditor.h"


using Jack::Server;


namespace Orza { namespace Steel { namespace Settings {


class Layout : public Orza::Steel::Widget::BaseWidget {

	public:

		Layout( Server * );

	private:

		/**
		 * Props
		 */

		Ui_Settings _UI;

		Server * _Server;


		/**
		 * Tabs
		 */

		Orza::Widget::Patchbay * _Patchbay;

		PedalEditor * _PedalEditor;

		StringEditor * _StringEditor;


};

} } }
