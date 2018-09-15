/**
 * Bridge
 */
#pragma once

#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>

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


	private:

		/**
		 * Props
		 */

		uint8_t _strings;

		vector<StringArea*> _areas;

		QWidget * _content;

		QVBoxLayout * _layout;


		/**
		 * Private helpers
		 */

		void setupLayout();

		StringArea * createStringArea( uint8_t index );

};

}; }; };
