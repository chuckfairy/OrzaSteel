/**
 * Bridge
 */
#pragma once

#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>

#include <Util/Dispatcher.h>

#include "StringArea.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {


class Bridge : public QWidget {

	Q_OBJECT;

	public:

		Bridge();
		Bridge( uint8_t );

		~Bridge() {};


		/**
		 * Main string changer
		 */

		void setNumStrings( uint8_t );


		/**
		 * String area handlers
		 */

		void handleStringDown( StringArea * );
		void handleStringUp( StringArea * );
		void handleStringClick( StringArea * );
		void handleStringPause( StringArea * );


	private:

		/**
		 * Props
		 */

		uint8_t _strings;

		vector<StringArea*> _areas;

		QWidget * _content;

		QVBoxLayout * _layout;


		/**
		 * Events
		 */

		Util::Event * _downEvent;
		Util::Event * _upEvent;
		Util::Event * _clickEvent;
		Util::Event * _pauseEvent;


		/**
		 * Private helpers
		 */

		void setupLayout();

		StringArea * createStringArea( uint8_t index );

		uint8_t getIndexFromStringArea( StringArea * );

};

}; }; };
