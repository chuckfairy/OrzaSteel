/**
 * Simple layout start
 */
#pragma once

#include <json/json.hpp>

#include <Jack/Server.h>
#include <Audio/StringInstrument.h>
#include <Settings/PresetLoader.h>

#include "StringEditor.h"
#include "PedalEditor.h"

using nlohmann::json;
using Orza::Steel::Audio::StringInstrument;



namespace Orza { namespace Steel { namespace Settings {


class InstrumentPresetLoader : public Orza::Layouts::PresetLoader {

	public:

		InstrumentPresetLoader( Jack::Server * , StringInstrument * ,
			StringEditor *,
			PedalEditor *
		);


		/**
		 * Virtuals
		 */

		void load( json settings );

	private:

		StringInstrument * _instrument;

		StringEditor * _stringEditor;
		 PedalEditor * _pedalEditor;

};

}; }; };
