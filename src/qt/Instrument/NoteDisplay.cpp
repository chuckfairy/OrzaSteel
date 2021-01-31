/**
 * Neck
 */
#include <iomanip>
#include <sstream>

#include "NoteDisplay.h"


using std::string;
using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


NoteDisplay::NoteDisplay(
	QLabel * widget
) :
	_widget(widget)
{
	update({});

	//Volume slider connection
	connect(
		this,
		SIGNAL( updateUI() ),
		this,
		SLOT( handleUpdate() )
	);
};


void NoteDisplay::update(vector<float_t> newPitches) {

	pitches = newPitches;

	emit updateUI();

};

void NoteDisplay::handleUpdate() {

	int pitchesSize = pitches.size();

	if(pitchesSize == 0) {
		_widget->setText("");
		return;
	}

	string text;

	for(int i = 0; i < pitchesSize; ++i) {
		float_t pitch = pitches[i];

		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << pitch;
		text = text + stream.str();

		if(( i + 1 ) != pitchesSize) {
			text = text + ",";
		}
	}

	_widget->setText(text.c_str());
};

} } }

