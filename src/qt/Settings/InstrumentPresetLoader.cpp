/**
 * Simple layout start
 */
#include "InstrumentPresetLoader.h"

using std::vector;
using nlohmann::json;
using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Audio::Pedal;



namespace Orza { namespace Steel { namespace Settings {


InstrumentPresetLoader::InstrumentPresetLoader(
	Jack::Server * server,
	StringInstrument * s,
	StringEditor * stringEditor,
	PedalEditor * pedalEditor,
	SoundEditor * soundEditor,
	Orza::Widget::Patchbay * patchbay
) :
	Orza::Layouts::PresetLoader( server, patchbay ),
	_instrument( s ),
	_stringEditor( stringEditor ),
	_soundEditor( soundEditor ),
	_pedalEditor( pedalEditor )
{
}

void InstrumentPresetLoader::load( json j ) {

	Orza::Layouts::PresetLoader::load(j);

	//Strings load
	if( ! j["strings"].empty() ) {
		vector<float_t> strings;
		for( json::iterator it = j["strings"].begin(); it != j["strings"].end(); ++it ) {
			json stringF = *it;
			strings.push_back(stringF);
			std::cout << "STRING " << stringF << "\n";
		}

		//Sets strings on module too
		_instrument->setStrings(strings);
		_stringEditor->buildFrom(strings);
	}

	_stringEditor->updateOctaves( ((int)j["octaves"]) );

	//
	if( ! j["pedals"].empty() ) {
		vector<Pedal*> pedals;

		for( json::iterator it = j["pedals"].begin(); it != j["pedals"].end(); ++it ) {
			Pedal * pedal = new Pedal;

			json data = *it;
			string key = data["key"];
			pedal->key = (char)key.c_str()[0];
			pedal->label = data["label"];

			//@TODO maybe don't loop
			vector<int> strings = data["strings"];
			for( int t = 0; t < strings.size(); ++t ) {
				pedal->strings.push_back(strings[t]);
			}

			pedals.push_back(pedal);
		}

		//Sets up module too
		_pedalEditor->buildFrom(pedals);
	}

	//Tonebar image
	if( ! j["tonebar"].empty() ) {
		_stringEditor->updateTonebarImage(j["tonebar"]);
	}


	//@TODO
	if( ! j["envelope"].empty() ) {
		//_soundEditor->
		EnvelopeEditor * envEditor = _soundEditor->getEnvelopeEditor();
		Envelope * env = envEditor->getEnvelope();

		env->setAttack((float)j["envelope"]["attack"]);
		env->setDecay((float)j["envelope"]["decay"]);
		env->setSustain((float)j["envelope"]["sustain"]);
		env->setRelease((float)j["envelope"]["release"]);
	}

	if( ! j["neck"].empty() ) {
	}
};

}; }; };
