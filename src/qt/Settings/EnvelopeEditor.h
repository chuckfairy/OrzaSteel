/**
 * String editor
 */
#pragma once

#include <vector>

#include <QtGui>
#include <QtCore>
#include <QWidget>

#include <Audio/Envelope.h>

#include <ui_EnvelopeEditor.h>


using Orza::Audio::Envelope;


namespace Orza { namespace Steel { namespace Settings {

class EnvelopeEditor : public QWidget {

	Q_OBJECT;

	public:

		static const char * ENVELOPE_CHANGE;

		EnvelopeEditor(Envelope *);
		~EnvelopeEditor() {};


		/**
		 * Values
		 */

		Envelope * getEnvelope();

		void setEnvelope(Envelope *);


	public slots:

		void handleAttackChange(int);
		void handleDecayChange(int);
		void handleSustainChange(int);
		void handleReleaseChange(int);


	signals:

		void EnvelopeChange(Envelope *);


	private:

		Envelope * _env;

		Ui_EnvelopeEditor _UI;

		void setup();

		void emitUpdate();

};

} } }
