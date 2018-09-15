/**
 * Module
 */
#pragma once

#include <Module/BaseModule.h>

#include "Bridge.h"
#include "Neck.h"

using Orza::Steel::BaseModule;
using Orza::Steel::Window;


namespace Orza { namespace Steel { namespace Instrument {

/**
 * Main
 */

class Module : public BaseModule {

	public:

		Module( Window * );

		~Module() {};

	private:

		Bridge * _bridge;

		Neck * _neck;

};

} } }
