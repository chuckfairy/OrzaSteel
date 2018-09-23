/**
 * Neck
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>

#include "Tonebar.h"


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {

class Neck : public QWidget {

	public:

		Neck();
		~Neck() {};

		/**
		 * setter for positions creation
		 */

		void setPositions( uint8_t );

		/**
		 * Get positions from bridge setup
		 */

		vector<uint8_t> getPositions();


		/**
		 * Obj getters
		 */

		Tonebar * getTonebar() {

			return _Bar;

		};


	private:

		/**
		 * Props
		 */

		vector<uint8_t> _positions;

		QVBoxLayout * _layout;


		/**
		 * Tonebar
		 */

		Tonebar * _Bar;

		/**
		 * Internals
		 */

		void createBridgeArea( uint8_t );
		void setupLayout();

};

} } }
