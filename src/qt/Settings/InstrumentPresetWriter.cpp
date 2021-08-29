/**
 * Layout writer qt ext
 */
#include "InstrumentPresetWriter.h"

#include <Audio/Wave/BaseWave.h>

using std::string;
using std::vector;

using nlohmann::json;

using Audio::Patchbay;

using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::Pedal;
using Orza::Steel::Audio::Wave::BaseWave;
using Orza::Audio::Envelope;



namespace Orza { namespace Steel { namespace Settings {


InstrumentPresetWriter::InstrumentPresetWriter( Module * m, StringInstrument * s ) :
	_module(m),
	_instrument( s )
{
};

void InstrumentPresetWriter::writeLayoutToFile( string fileName, Patchbay * p ) {

	json output = getPatchbayJSON( fileName, p );


	//Strings
	const vector<float_t> * strings = _instrument->getStrings();
	for(int i = 0; i < strings->size(); ++i) {
		output["strings"].push_back(strings->at(i));
	}

	output["octaves"] = _instrument->getOctaves();
	output["semitones"] = _instrument->getSemitones();

	//Pedals
	const vector<Pedal*> * pedals = _instrument->getPedals();
	for(int i = 0; i < pedals->size(); ++i) {
		Pedal * pedal = pedals->at(i);

		json pedalJSON;

		pedalJSON["key"] = string(1, pedal->key);
		pedalJSON["label"] = pedal->label;
		pedalJSON["steps"] = pedal->steps;
		pedalJSON["strings"] = pedal->strings;

		output["pedals"].push_back(pedalJSON);
	}

	//Sound


	output["wave"] = _module->getWave()->getType();

	Envelope * env = _module->getEnvelope();

	output["envelope"]["attack"] = env->getAttack();
	output["envelope"]["decay"] = env->getDecay();
	output["envelope"]["sustain"] = env->getSustain();
	output["envelope"]["release"] = env->getRelease();

	//View
	output["tonebar_image"] = _module->getTonebarImage();
	//output["neck_colors"] = "";

	//Save json

	saveToFile( fileName.c_str(), output );

};

}; }; };
