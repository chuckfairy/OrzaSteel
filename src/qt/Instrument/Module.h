/**
 * Module
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <jack/jack.h>

#include <Audio/StringInstrument.h>
#include <Audio/InstrumentOutput.h>

#include <Audio/Pedal.h>

#include <Audio/Envelope.h>

#include <Module/BaseModule.h>

#include <Audio/Wave/BaseWave.h>
#include <Audio/Wave/NullWave.h>
#include <Audio/Wave/SineWave.h>
#include <Audio/Wave/TriangleWave.h>
#include <Audio/Wave/SquareWave.h>

#include "Bridge.h"
#include "Neck.h"
#include "NoteDisplay.h"
#include "PedalWrap.h"
#include "PortInterface.h"
#include <Midi/MidiReader.h>


using std::map;
using std::vector;

using Orza::Audio::Envelope;

using Orza::Steel::BaseModule;
using Orza::Steel::Window;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::InstrumentOutput;
using Orza::Steel::Audio::Pedal;

using Orza::Steel::Audio::Wave::BaseWave;
using Orza::Steel::Audio::Wave::NullWave;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Main
 */

class Module : public QWidget, public BaseModule {

	Q_OBJECT;

	public:

		Module( Window * );

		~Module() {};


		/**
		 * Set strings main
		 */

		void setStrings( vector<float_t> );

		void setStringState(int index, bool state = false);

		void setPedalState(int index, bool state = false);

		void setNeckPitch(float_t);

		void setTonebarImage(string);


		/**
		 * Main jack stuff
		 */

		void process( jack_nframes_t );

		void handleKeyEvent( QKeyEvent * event );

		void handleResize( QResizeEvent * event );


		/**
		 * Pedal stuff
		 */

		void setPedals( vector<Pedal*> * );


		/**
		 * Insrument
		 */

		StringInstrument * getInstrument() {

			return _instrument;

		};


		/**
		 * Update octaves and semitones on neck
		 */
		void setOctaves( int );
		void setSemiTones( int );

		/**
		 * Wave
		 */
		void setWave( BaseWave * );
		BaseWave * getWave();

		/**
		 * Envelope
		 */
		void setEnvelope(Envelope *);
		Envelope * getEnvelope();


	public slots:

		void handleVolumeChanged();

		void setVolumeValue(float);


	private:

		/**
		 * GUI / submod
		 */

		Bridge * _bridge;

		Neck * _neck;


		PedalWrap * _pedalWrap;

		vector<Pedal*> * _pedals;

		NoteDisplay * _noteDisplay;


		/**
		 * Audio
		 */

		PortInterface * _stereoInterface;

		StringInstrument * _instrument;

		InstrumentOutput * _outputter;

		MidiReader * _midiReader;


		/**
		 * Wave for output
		 */

		BaseWave * _wave;

		Envelope * _envelope;


		/**
		 * Internals
		 */

		bool HAS_CHANGE = false;

		map<uint8_t, float_t> getHandMap( vector<uint8_t> * bridged );

		map<uint8_t, float_t> getHandMapPitches( vector<float_t>, map<uint8_t, float_t> );

		void processPedals( char keyPressed, bool active );

		void midiSetup();

	signals:

		void emitVolumeChange(float);

};

} } }
