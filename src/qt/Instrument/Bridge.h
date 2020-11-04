/**
 * Bridge
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>

#include <Util/Dispatcher.h>

#include "StringArea.h"


using std::map;
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
		 * String handlers
		 */

		void setStringDown( uint8_t index );
		void setStringUp( uint8_t index );

		void handleStringDown( StringArea * );
		void handleStringUp( StringArea * );


		/**
		 * Processing
		 */

		vector<uint8_t> * getHand() {

			return &_hand;

		};


		/**
		 * Needs updating outside
		 */

		bool hasChange() {

			return HAS_CHANGE;

		};

		void setChanged() {

			HAS_CHANGE = false;

		};


	private:

		/**
		 * Props
		 */

		uint8_t _strings;

		vector<StringArea*> _areas;

		QWidget * _content;

		QVBoxLayout * _layout;

		vector<uint8_t> _hand;

		bool HAS_CHANGE = false;

		uint8_t numberActive;


		/**
		 * Events
		 */

		Util::Event * _downEvent;
		Util::Event * _upEvent;


		/**
		 * Private helpers
		 */

		void setupLayout();

		StringArea * createStringArea( uint8_t index );

		uint8_t getIndexFromStringArea( StringArea * );

		void clearArea();

};

}; }; };
