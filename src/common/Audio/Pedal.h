/**
 * Pedal
 */
#pragma once

#include <cstdint>
#include <vector>


using std::vector;


namespace Orza { namespace Steel { namespace Audio {

struct Pedal {

	const char * label;

	vector<uint8_t> strings;

	uint8_t steps = 0;

	bool on = false;

};

} } }
