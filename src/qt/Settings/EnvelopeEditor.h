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

		EnvelopeEditor();
		~EnvelopeEditor() {};


		/**
		 * Values
		 */

		Envelope * getEnvelope();


	public slots:

		void handleAttackChange(int);


	signals:

		Envelope * EnvelopeChange();


	private:

		Envelope * _env;

		Ui_EnvelopeEditor _UI;

};

} } }
