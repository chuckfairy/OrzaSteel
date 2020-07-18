/**
 * Midi reader impl
 * Create ports on construct
 */
#include "MidiReader.h"

namespace Orza { namespace Steel { namespace Instrument {


MidiReader::MidiReader(::Audio::Server * server) :
	_server(server)
{
	//Setup midi port
	Audio::MidiHost * midiHost = _server->getMidiHost();

	_port = midiHost->createOutputPort("OrzaPad");

	//Setup midi host callback
	_Event = new Midi::EventMessage<MidiReader>( this );

	const char * eventName = jack_port_name( _port->nameString );

	midiHost->on( eventName, _Event );

};

/**
 * Main reader
 */
void MidiReader::onMidiMessage( Orza::Midi::Event * event ) {

};

} } }
