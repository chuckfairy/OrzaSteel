/**
 * string editor
 */
#include <Util/Vector.h>

#include "StringEditor.h"

#include <Widget/Events/NodeRemoveEvent.h>

#include <Window.h>

#include <Instrument/Module.h>


using Orza::Widget::NodeRemoveEvent;
using Orza::Steel::Instrument::Module;
using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Settings {

StringEditor::StringEditor( Window * window ) :
    _win( window )
{

	_UI.setupUi( this );


	//Tonebar image selector extras
	_UI.tonebar_image_input->SetShowFullFile(false);

	connect(
		_UI.add_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handleAddClick() )
	);

	connect(
		_UI.octave_input,
		SIGNAL( currentIndexChanged( int ) ),
		this,
		SLOT( updateOctaves( int ) )
	);

	connect(
		_UI.semitone_input,
		SIGNAL( currentIndexChanged( int ) ),
		this,
		SLOT( updateSemiTones( int ) )
	);

	connect(
		_UI.tonebar_image_input,
		SIGNAL( FileChanged( string ) ),
		this,
		SLOT( updateTonebarImage( string ) )
	);

};


void StringEditor::handleAddClick() {

	StringEditArea * area = new StringEditArea();

	_UI.strings_content->addWidget( area );

	addNode( area );

	updateInstrument();

};


/**
 * Build from
 */

void StringEditor::buildFrom( vector<float> strings ) {

	clearArea();

	_building = true;

	for( int i = 0; i < strings.size(); ++ i ) {

		StringEditArea * area = new StringEditArea();
		_UI.strings_content->addWidget( area );

		area->setStringNote( strings[ i ] );

		addNode( area );

	}

	_building = false;

	updateInstrument();

};


/**
 * Main update of global
 */

void StringEditor::updateInstrument() {

	if( _building ) {
		return;
	}

	std::cout << "Updating instrument from editor\n";

	vector<float_t> strings;

	vector<StringEditArea*> _areas = _nodes.getAll<StringEditArea>();

	for( int i = 0; i < _areas.size(); ++ i ) {

		strings.push_back( _areas[i]->getStringNote() );

	}

	Module * insta = (Module*) _win->getModules()[0];

	insta->setStrings( strings );

};


/**
 * Update handlers
 */

void StringEditor::afterRemove() {

	updateInstrument();

};

void StringEditor::handleNodeUpdate( TreeNode * node ) {

	updateInstrument();

};

/**
 * Updates octaves for insrument
 */
void StringEditor::updateOctaves( int index ) {

	//@TODO move
	Module * insta = (Module*) _win->getModules()[0];

	int octaves = _UI.octave_input->currentText().toInt();

	insta->setOctaves(octaves);

}

/**
 * Updates octaves for insrument
 */
void StringEditor::updateSemiTones( int index ) {

	//@TODO move
	Module * insta = (Module*) _win->getModules()[0];

	int semitones = _UI.semitone_input->currentText().toInt();

	insta->setSemiTones(semitones);

}

/**
 * Updates octaves for insrument
 */
void StringEditor::updateTonebarImage( string file ) {

	//@TODO move
	Module * insta = (Module*) _win->getModules()[0];

	insta->setTonebarImage(file);

}


/**
 * Tree node overrides
 */

void StringEditor::addNode( TreeNode * area ) {

	TreeNode::addNode( area );

	Util::Event * e = new UpdateEvent<StringEditor, TreeNode>( this );

	area->on( StringEditArea::NODE_UPDATE_EVENT, e );

	updateInstrument();

};

void StringEditor::remove( TreeNode * area ) {

	_UI.strings_content->removeWidget( (StringEditArea *)area );

	TreeNode::remove( (StringEditArea *)area );

	updateInstrument();

};


void StringEditor::clearArea() {

	int size = _nodes.size();
	for (int i = 0; i < size; ++i) {
		remove(_nodes.getByIndex(0));
	}

}

} } }
