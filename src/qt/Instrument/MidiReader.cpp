/**
 * Midi reader impl
 * Create ports on construct
 */
#include <Midi/Note.h>

#include "MidiReader.h"


namespace Orza { namespace Steel { namespace Instrument {


MidiReader::MidiReader(::Audio::Server * server) :
	_server(server)
{
	//Setup midi port
	::Audio::MidiHost * midiHost = _server->getMidiHost();

	_port = midiHost->createOutputPort("OrzaPad");

	setMaps();


	//Setup midi host callback
	_Event = new Midi::EventMessage<MidiReader>( this );

	const char * eventName = jack_port_name( _port->nameString.c_str() );

	midiHost->on( eventName, _Event );

};


/**
 * Instrument setting
 */

void MidiReader::changeInstrument(StringInstrument * instrument) {

};


void MidiReader::setFromInstrument(StringInstrument * instrument) {

}

/**
 * Main reader
 */
void MidiReader::onMidiMessage( Orza::Midi::Event * event ) {

	switch(event->type) {
		case Midi::EVENT_NOTE_ON:
		case Midi::EVENT_NOTE_OFF:
			setNoteValues(event);
			break;

		case Midi::EVENT_CONTROL_CHANGE:
			setControlValues(event);
			break;
	}

	_hasChanges = true;

};


/**
 * Map setting for us as hash key lookups
 */

void MidiReader::setMaps() {

	int cnt = sizeof(Orza::Midi::NOTE_NAMES);
	int stringMidiLength = stringMidiStart + stringMidiLength;
	int pedalMidiLength = pedalMidiStart + pedalMidiLength;

	for(int i = 0; i < cnt; ++i) {
		stringMap[i] = (stringMidiStart >= i && i < stringMidiLength)
			? i - stringMidiStart
			: -1;
		pedalMap[i] = (pedalMidiStart >= i && i < pedalMidiLength)
			? i - pedalMidiStart
			: -1;
	}

};


void MidiReader::setNoteValues(Orza::Midi::Event * event) {

	//Is a string press
	if(stringMap[event->pitch]) {
		_strings[stringMap[event->pitch]] = (event->type == Midi::EVENT_NOTE_ON);
	}

	//Is a pedal press
	if(pedalMap[event->pitch]) {
		_pedals[pedalMap[event->pitch]] = (event->type == Midi::EVENT_NOTE_ON);
	}

};


void MidiReader::setControlValues(Orza::Midi::Event * event) {

	switch(event->controlNumber) {
		//case pitchControlNumber:
			//_pitch = event->value / 127;
			//break;

		//case volumeControlNumber:
			//_volume = event->value / 127;
			//break;
	}

};

} } }
