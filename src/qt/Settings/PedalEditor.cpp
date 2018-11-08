/**
 * Pedal editor
 */
#include <Util/Vector.h>

#include "PedalEditor.h"

#include <Widget/Events/NodeRemoveEvent.h>

#include <Window.h>

#include <Instrument/Module.h>


using Orza::Widget::NodeRemoveEvent;
using Orza::Steel::Instrument::Module;
using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Settings {

PedalEditor::PedalEditor( Window * window ) :
    _win( window )
{

	_UI.setupUi( this );

	connect(
		_UI.add_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handleAddClick() )
	);

};

void PedalEditor::handleAddClick() {

    PedalEditArea * area = new PedalEditArea();

    _UI.pedal_content->addWidget( area );

    addNode( area );

};

/**
 * Build from
 */

void PedalEditor::buildFrom( vector<Pedal*> pedals ) {

    for( int i = 0; i < pedals.size(); ++ i ) {

        Pedal * pedal = pedals[ i ];
        PedalEditArea * area = new PedalEditArea();
        _UI.pedal_content->addWidget( area );

        area->setLabel( pedal->label.c_str() );
        area->setModifier( pedal->steps );
        area->setStrings( pedal->strings );
        area->setControlKey( pedal->key );

        addNode( area );

    }

};


/**
 * Main update of global
 */

void PedalEditor::updateInstrument() {

    std::cout << "Updating instrument from editor\n";

    vector<Pedal*> pedals;

    vector<PedalEditArea*> _areas = _nodes.getAll<PedalEditArea>();

    for( int i = 0; i < _areas.size(); ++ i ) {

        pedals.push_back( _areas[i]->getAsPedal() );

    }

    Module * insta = (Module*) _win->getModules()[0];

    insta->setPedals( &pedals );

};


/**
 * Update handlers
 */

void PedalEditor::afterRemove() {

    updateInstrument();
};

void PedalEditor::handleNodeUpdate( TreeNode * node ) {

    updateInstrument();

};


/**
 * Tree node overrides
 */

void PedalEditor::addNode( TreeNode * area ) {

    TreeNode::addNode( area );

    Util::Event * e = new UpdateEvent<PedalEditor, TreeNode>( this );

    area->on( PedalEditArea::NODE_UPDATE_EVENT, e );

    updateInstrument();

};

void PedalEditor::remove( TreeNode * area ) {

    _UI.pedal_content->removeWidget( (PedalEditArea *)area );

    TreeNode::remove( (PedalEditArea *)area );

    updateInstrument();

};

} } }
