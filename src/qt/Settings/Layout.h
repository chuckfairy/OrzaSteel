/**
 * Layout toplevel settings
 */
#pragma once

#include <Widget/BaseWidget.h>

#include <Widget/Patchbay.h>

#include <Jack/Server.h>

#include <ui_Settings.h>


using Jack::Server;


namespace Orza { namespace Steel { namespace Settings {


class Layout : public Orza::Steel::Widget::BaseWidget {

    public:

        Layout( Server * );

    private:

        Ui_Settings _UI;

        Orza::Widget::Patchbay * _Patchbay;

        Server * _Server;

};

} } }
