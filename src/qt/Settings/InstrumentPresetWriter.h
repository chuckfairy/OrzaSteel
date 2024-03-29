/**
 * Layout writer qt ext
 */
#pragma once

#include <string>
#include <vector>

#include <json/json.hpp>

#include <Audio/Patchbay.h>
#include <Layouts/LayoutWriter.h>

#include <Audio/StringInstrument.h>

#include <Instrument/Module.h>


using std::string;
using std::vector;
using nlohmann::json;

using Audio::Patchbay;

using Orza::Steel::Audio::StringInstrument;
using Orza::Steel::Instrument::Module;



namespace Orza { namespace Steel { namespace Settings {


class InstrumentPresetWriter : public Orza::Layouts::LayoutWriter {

	public:

		 InstrumentPresetWriter( Module *, StringInstrument * );
		 ~InstrumentPresetWriter() {};

		 /**
		  * @TODO
		  */
		void writeLayoutToFile( string fileName, Patchbay * p );

	private:

		StringInstrument * _instrument;
		Module * _module;

};

}; }; };
