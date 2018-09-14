/**
 * Instrument output to jack capable
 */
#pragma once

#include "InstrumentOutput.h"


namespace Orza { namespace Steel { namespace Audio {

/**
 * Constructor
 */

InstrumentOutput::InstrumentOutput( BaseInstrument * inst ) :
	_instrument( inst )
{
}


/**
 * Get output main method
 */

jack_default_audio_sample_t * InstrumentOutput::getOutput( jack_nframes_t nframes ) {

	int i;

	void* port_buf = jack_port_get_buffer(input_port, nframes);

	jack_default_audio_sample_t * out;

	jack_midi_event_t in_event;
	jack_nframes_t event_index = 0;
	jack_nframes_t event_count = jack_midi_get_event_count(port_buf);

	jack_midi_event_get(&in_event, port_buf, 0);

	vector<float_t> freqs = _instrument->getPitches();

	for( i=0; i < nframes; i++ ) {

		if( ( in_event.time == i ) && ( event_index < event_count ) ) {

			if(((*(in_event.buffer) & 0xf0)) == 0x90) {

				/* note on */
				note = *(in_event.buffer + 1);
				note_on = 1.0;

			} else if( ((*(in_event.buffer)) & 0xf0) == 0x80 ) {

				/* note off */
				note = *(in_event.buffer + 1);
				note_on = 0.0;
			}

			event_index++;

			if(event_index < event_count) {
				jack_midi_event_get(&in_event, port_buf, event_index);
			}

		}

		ramp += note_frqs[note];
		ramp = (ramp > 1.0) ? ramp - 2.0 : ramp;
		out[i] = note_on*sin(2*M_PI*ramp);

	}

	return out;

};

} } }
