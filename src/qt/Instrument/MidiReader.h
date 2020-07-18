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

using std::vector;

namespace Orza { namespace Steel { namespace Instrument {

class MidiReader {

	public:

		MidiReader(::Audio::Server *);

		void onMidiMessage( Orza::Midi::Event * event );

		bool hasChanges();

		vector<uint8_t> getPitches();
		vector<int, bool> getPedals();
		float getTonebar();

	private:

		::Audio::Server * _server;

		::Audio::Port * _port;

		Midi::EventMessage<MidiReader> * _Event;
}

} } }
