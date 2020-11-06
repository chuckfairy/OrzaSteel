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

	_port = midiHost->createInputPort("OrzaSteel");
	midiHost->addInput(_port);

	std::cout << "MIDI PORT CREATED  " << _port->getName() << "\n";

	setMaps();


	//Setup midi host callback
	_Event = new Midi::EventMessage<MidiReader>( this );

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

	//std::cout << "Received Midi Event\n";

	switch(event->type) {
		case Midi::EVENT_NOTE_ON:
		case Midi::EVENT_NOTE_OFF:
			setNoteValues(event);
			break;

		case Midi::EVENT_CONTROL_CHANGE:
			setControlValues(event);
			break;

		default:
			return;
	}

	_hasChanges = true;

};


/**
 * Map setting for us as hash key lookups
 */

void MidiReader::setMaps() {

	int cnt = sizeof(Orza::Midi::NOTE_NAMES) / sizeof(Orza::Midi::NOTE_NAMES[0]);
	int stringMidiLength = stringMidiStart + stringMidiCount;
	int pedalMidiLength = pedalMidiStart + pedalMidiCount;

	for(int i = 0; i < cnt; ++i) {
		stringMap[i] = (i >= stringMidiStart && i < stringMidiLength)
			? i - stringMidiStart
			: -1;

		pedalMap[i] = (i >= pedalMidiStart && i < pedalMidiLength)
			? i - pedalMidiStart
			: -1;
	}

};


void MidiReader::setNoteValues(Orza::Midi::Event * event) {

	//Is a string press
	if(stringMap[event->pitch] != -1) {
		std::cout << "Midi Note Has String " << stringMap[event->pitch] << " "
			<< (event->type == Midi::EVENT_NOTE_ON) << "\n";

		_strings[stringMap[event->pitch]] = (event->type == Midi::EVENT_NOTE_ON);

		_hasChanges = true;
	}

	//Is a pedal press
	if(pedalMap[event->pitch] != -1) {
		std::cout << "Pedal Note Has Event " << pedalMap[event->pitch] << " "
			<< (event->type == Midi::EVENT_NOTE_ON) << "\n";

		_pedals[pedalMap[event->pitch]] = (event->type == Midi::EVENT_NOTE_ON);

		_hasChanges = true;
	}

};


void MidiReader::setControlValues(Orza::Midi::Event * event) {

	if(event->controlNumber == pitchControlNumber) {
		float newPitch = (float)event->controlValue / 127.0f;

		if(newPitch == _pitch) {
			return;
		}

		_pitch = newPitch;
		std::cout << "Pitch Has Event " << _pitch << "\n";
		_hasChanges = true;
	}

	else if(event->controlNumber == volumeControlNumber) {
		float newVolume = ((float)event->controlValue) / 127.0f;

		if(newVolume == _volume) {
			return;
		}

		_volume = newVolume;

		std::cout << "Volume Has Event " << _volume<< "\n";
		_hasChanges = true;
	}

};


bool MidiReader::hasChanges() {

	return _hasChanges;

};

void MidiReader::changesChecked() {

	_hasChanges = false;

};



map<int, bool> MidiReader::getStrings() {

	return _strings;

};

map<int, bool> MidiReader::getPedals() {

	return _pedals;
};


float MidiReader::getVolume() {

	return _volume;

}

float MidiReader::getPitch() {

	return _pitch;

};



void MidiReader::connectPort(Port* output) {

	std::cout << "CONNECTING MIDI PORT " << output->getName() << "\n";

	::Audio::MidiHost * midiHost = _server->getMidiHost();

	midiHost->addOutput(output);

	const char * eventName = output->getName();

	midiHost->on( eventName, _Event );


};


} } }
