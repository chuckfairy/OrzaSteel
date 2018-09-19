/**
 * Neck
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

#include <QtGui>
#include <QWidget>


using std::vector;


namespace Orza { namespace Steel { namespace Instrument {

class Neck : public QWidget {

	Q_OBJECT;

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


	private:

		vector<uint8_t> _positions;

		void createBridgeArea( uint8_t );

};

} } }
