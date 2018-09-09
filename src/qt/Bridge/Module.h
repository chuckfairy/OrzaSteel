/**
 * Module
 */
#pragma once

#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>

#include "StringArea.h"

using std::vector;

namespace Orza { namespace Steel { namespace Bridge {

class Module {

	public:

		Module();

		/**
		 * Getters
		 */

		QWidget * getWidget() {

			return _content;

		};


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


		/**
		 * Private helpers
		 */

		void createStringArea( uint8_t index );

};

}; }; };
