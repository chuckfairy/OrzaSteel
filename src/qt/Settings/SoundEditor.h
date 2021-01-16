/**
 * Sound editor
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Audio/Wave/BaseWave.h>
#include <Audio/Wave/NullWave.h>
#include <Audio/Wave/SineWave.h>
#include <Audio/Wave/TriangleWave.h>
#include <Audio/Wave/SquareWave.h>
#include <Audio/Wave/SawtoothWave.h>

#include <Audio/Envelope.h>

#include "EnvelopeEditor.h"

#include <ui_SoundEditor.h>


/**
 * Forwarding
 */

namespace Orza { namespace Steel {

class Window;

} }

using std::vector;

using Orza::Audio::Envelope;
using Orza::Steel::Window;
using Orza::Steel::Audio::Wave::BaseWave;


/**
 * Main
 */

namespace Orza { namespace Steel { namespace Settings {


class SoundEditor : public QWidget {

    Q_OBJECT;

	public:

		SoundEditor( Window * );
		~SoundEditor() {};


		/**
		 * API
		 */

		void handleWaveChange( BaseWave * );


	public slots:

		/**
		 * Events
		 */

		void handleWaveCombo(int);


	private:

		Ui_SoundEditor _UI;

		Window * _win;

		EnvelopeEditor * _envelopeEditor;

		bool _building = false;

		vector<BaseWave*> _waves;

		Envelope * _env;

		void buildWaveformCombo();

};

} } }
