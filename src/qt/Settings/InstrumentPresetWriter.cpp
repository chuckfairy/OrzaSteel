/**
 * Layout writer qt ext
 */
#include "InstrumentPresetWriter.h"

using std::string;
using std::vector;
using nlohmann::json;
using Audio::Patchbay;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::Pedal;



namespace Orza { namespace Steel { namespace Settings {


InstrumentPresetWriter::InstrumentPresetWriter( StringInstrument * s ) :
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

	//Pedals
	const vector<Pedal*> * pedals = _instrument->getPedals();
	for(int i = 0; i < pedals->size(); ++i) {
		Pedal * pedal = pedals->at(i);

		json pedalJSON;

		pedalJSON["key"] = pedal->key;
		pedalJSON["label"] = pedal->label;
		pedalJSON["steps"] = pedal->steps;
		pedalJSON["strings"] = pedal->strings;

		output["pedals"].push_back(pedalJSON);
	}


	//Save json

	saveToFile( fileName.c_str(), output );

};

}; }; };
