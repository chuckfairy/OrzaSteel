/**
 * Module impl instrument
 *
 * What Midi we Read
 * ====
 * Strings down
 * 22-48
 *
 * Pedals Down
 * 49-61
 *
 * Tonebar
 * Midi Control Port 14
 *
 * Volume
 * Midi Control Port 15
 *
 */
#pragma once

#include <vector>
#include <map>
#include <cmath>
#include <cstdint>

#include <Audio/Port.h>
#include <Audio/Server.h>
#include <Audio/PluginPortContainer.h>
#include <Audio/MidiControlRange.h>

#include <Midi/Control.h>
#include <Midi/Events.h>
#include <Midi/Events/EventMessage.h>

#include <Audio/StringInstrument.h>

#include <Jack/Midi.h>


using std::map;
using std::vector;

using Orza::Steel::Audio::StringInstrument;
using Audio::Port;


namespace Orza { namespace Steel { namespace Instrument {

class MidiReader {

	public:

		MidiReader(::Audio::Server *);

		void onMidiMessage( Orza::Midi::Event * event );

		void changeInstrument(StringInstrument *);

		void setFromInstrument(StringInstrument *);

		bool hasChanges();

		void changesChecked();

		map<int, bool> getStrings();
		map<int, bool> getPedals();

		float getVolume();
		float getPitch();

		void connectPort(Port*);


	private:

		bool _hasChanges = false;

		::Audio::Server * _server;

		::Audio::Port * _port;

		Midi::EventMessage<MidiReader> * _Event;

		//Values
		float _pitch = 0.0f;
		float _volume = 1.0f;

		//Midi number Defaults
		int stringMidiStart = 24;
		int stringMidiCount = 23;

		int pedalMidiStart = 48;
		int pedalMidiCount = 23;

		//Internal maps
		map<int, int> stringMap;
		map<int, int> pedalMap;

		map<int, bool> _strings;
		map<int, bool> _pedals;


		//Control mapping
		int pitchControlNumber = 14;
		int volumeControlNumber = 15;

		//Interal helpers
		void setMaps();

		//Midi handling
		void setNoteValues(Orza::Midi::Event * Event);

		void setControlValues(Orza::Midi::Event * Event);

};

} } }
