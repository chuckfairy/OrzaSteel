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

#include <Jack/Midi.h>

using std::map;
using std::vector;

namespace Orza { namespace Steel { namespace Instrument {

class MidiReader {

	public:

		MidiReader(::Audio::Server *);

		void onMidiMessage( Orza::Midi::Event * event );

		bool hasChanges();

		void resetChanges();

		vector<uint8_t> getPitches();
		vector<int, bool> getPedals();
		float getTonebar();

	private:

		bool _hasChanges = false;

		::Audio::Server * _server;

		::Audio::Port * _port;

		Midi::EventMessage<MidiReader> * _Event;

		//Midi number Defaults
		int stringMidiStart = 22;
		int stringMidiCount = 24;

		int pedalMidiStart = 46;
		int pedalMidiCount = 24;

		//Internal maps
		map<int, bool> stringMap;
		map<int, bool> pedalMap;

		map<int, bool> _strings;
		map<int, bool> _pedals;

		void setMaps();

		//Midi handling
		void setNoteValues(Orza::Midi::Event * Event);

		void setControlValues(Orza::Midi::Event * Event);

};

} } }
