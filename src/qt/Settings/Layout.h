/**
 * Layout toplevel settings
 */
#pragma once

#include <Widget/BaseWidget.h>


#include <ui_Settings.h>


namespace Orza { namespace Steel { namespace Settings {


class Layout : public Orza::Steel::Widget::BaseWidget {

    public:

        Layout();

    private:

        Ui_Settings _UI;

};


} } }
