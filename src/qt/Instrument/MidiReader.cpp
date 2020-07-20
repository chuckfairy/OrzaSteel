/**
 * Midi reader impl
 * Create ports on construct
 */
#include <Midi/Note.h>

#include "MidiReader.h"

using Orza::Midi;

namespace Orza { namespace Steel { namespace Instrument {


MidiReader::MidiReader(::Audio::Server * server) :
	_server(server)
{
	//Setup midi port
	Audio::MidiHost * midiHost = _server->getMidiHost();

	_port = midiHost->createOutputPort("OrzaPad");

	setMaps();


	//Setup midi host callback
	_Event = new Midi::EventMessage<MidiReader>( this );

	const char * eventName = jack_port_name( _port->nameString );

	midiHost->on( eventName, _Event );

};

/**
 * Main reader
 */
void MidiReader::onMidiMessage( Orza::Midi::Event * event ) {

	switch(event->type) {
		case EVENT_NOTE_ON:
		case EVENT_NOTE_OFF:
			setNoteValues(event);
			break;

		case EVENT_CONTROL_CHANGE:
			setControlValues(event);
			break;
	}

	_hasChanges = true;

};

void MidiReader::setMaps() {

	int cnt = sizeof(Orza::Midi::NOTE_NAMES);

	for(int i = 0; i < cnt; ++i) {
		//stringMap[i] = ;
		//pedalMap[i] = ;
	}

};

void MidiReader::setNoteValues(Orza::Midi::Event * Event) {

};


void MidiReader::setControlValues(Orza::Midi::Event * Event) {

};

} } }
