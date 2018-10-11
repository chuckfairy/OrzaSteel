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

	int8_t steps = 0;

	bool on = false;

	char key; //impl specific

	Pedal(
		const char * label_,
		vector<uint8_t> strings_,
		uint8_t steps_,
		char key_
	) {
		label = label_;
		strings = strings_;
		steps = steps_;
		key = key_;
	};

};

} } }
