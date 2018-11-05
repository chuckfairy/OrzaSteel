/**
 * Pedal
 */
#pragma once

#include <cstdint>
#include <string>
#include <vector>


using std::string;
using std::vector;


namespace Orza { namespace Steel { namespace Audio {

struct Pedal {

	string label;

	vector<uint8_t> strings;

	int8_t steps = 0;

	bool on = false;

	char key; //impl specific

	Pedal(
		const char * label_ = "",
		vector<uint8_t> strings_ = {},
		uint8_t steps_ = 0,
		char key_ = '0'
	) {
		label = label_;
		strings = strings_;
		steps = steps_;
		key = key_;
	};

};

} } }
