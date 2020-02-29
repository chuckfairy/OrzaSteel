/**
 * Simple layout start
 */
#pragma once

#include <json/json.hpp>

#include <Settings/PresetLoader.h>

using nlohmann::json;

using Jack::Server;

using Orza::Widget::Patchbay;



namespace Orza { namespace Steel {


class PresetLoader : public Orza::Settings::Layouts::PresetLoader {

	public:

		PresetLoader( Jack::Server * );


		/**
		 * Virtuals
		 */

		void load( json settings );

};

}; }; };
